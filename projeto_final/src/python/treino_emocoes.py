import pandas as pd
from flair.data import Sentence, Corpus
from flair.datasets import FlairDatapointDataset
from flair.models import TextClassifier
from flair.embeddings import WordEmbeddings, DocumentRNNEmbeddings
from flair.trainers import ModelTrainer
from sklearn.utils import shuffle
import itertools

class TreinadorModelo:
    def __init__(self, dataset_csv, embeddings_tipo='glove'):
        """
        Inicializa o treinador, carregando o dataset e os embeddings.
        """
        self.dataset_csv = dataset_csv
        self.embeddings = [WordEmbeddings(embeddings_tipo)]
        self.dataset = self.preparar_dataset()
        self.document_embeddings = DocumentRNNEmbeddings(
            self.embeddings, 
            hidden_size=256, 
            reproject_words=True, 
            reproject_words_dimension=128
        )
        self.corpus = self.criar_corpus()
        self.label_dictionary = self.corpus.make_label_dictionary(label_type='emocao')

    def preparar_dataset(self):
        """
        Prepara o dataset para o Flair.
        """
        df = pd.read_csv(self.dataset_csv, delimiter=';')
        frases = df['frase'].tolist()
        emocoes = df['emocao'].tolist()

        dataset = []
        for frase, emocao in zip(frases, emocoes):
            sentence = Sentence(frase)
            sentence.add_label('emocao', emocao)
            dataset.append(sentence)
        
        return shuffle(dataset, random_state=42)

    def criar_corpus(self):
        """
        Divide o dataset em treino e teste e cria o corpus do Flair.
        """
        tamanho_treino = int(0.8 * len(self.dataset))
        train_dataset = FlairDatapointDataset(self.dataset[:tamanho_treino])
        test_dataset = FlairDatapointDataset(self.dataset[tamanho_treino:])
        return Corpus(train=train_dataset, test=test_dataset, dev=None)

    def treinar_modelo(self, learning_rates, mini_batch_sizes, max_epochs, base_path='models'):
        """
        Treina o modelo usando combinações de hiperparâmetros.
        """
        classifier = TextClassifier(
            self.document_embeddings, 
            label_dictionary=self.label_dictionary, 
            multi_label=False, 
            label_type='emocao'
        )
        trainer = ModelTrainer(classifier, self.corpus)
        param_grid = list(itertools.product(learning_rates, mini_batch_sizes, max_epochs))

        best_f1_score = 0
        best_params = None

        for lr, batch_size, epochs in param_grid:
            print(f"Treinando com lr={lr}, batch_size={batch_size}, epochs={epochs}")
            
            # Treinamento
            trainer.train(
                base_path=f'{base_path}/modelo_de_emocoes_lr{lr}_bs{batch_size}_ep{epochs}',
                learning_rate=lr,
                mini_batch_size=batch_size,
                max_epochs=epochs
            )
            
            # Avaliação
            result = classifier.evaluate(self.corpus.test, gold_label_type='emocao')
            f1_score = result.main_score
            
            # Atualizar o melhor modelo
            if f1_score > best_f1_score:
                best_f1_score = f1_score
                best_params = (lr, batch_size, epochs)
            
            print(f"F1 Score: {f1_score}")
            print(f"Melhores parâmetros até agora: {best_params} com F1: {best_f1_score}")

        print(f"Melhores hiperparâmetros: lr={best_params[0]}, batch_size={best_params[1]}, epochs={best_params[2]}")

# Exemplo de uso
if __name__ == "__main__":
    treinador = TreinadorModelo('data/input/dataset_emocoes.csv')
    treinador.treinar_modelo(
        learning_rates=[0.1],
        mini_batch_sizes=[64],
        max_epochs=[10]
    )
