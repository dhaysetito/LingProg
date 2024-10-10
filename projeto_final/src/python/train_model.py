import pandas as pd
from flair.data import Sentence

# Carregar os dados do arquivo CSV
df = pd.read_csv("dataset_2.csv", delimiter=';')

# Verificar as primeiras linhas do dataset
print(df.head())

# ------------------  Preparar os dados --------------------

# Carregar as frases e os sentimentos do DataFrame
frases = df['frase'].tolist()
emocoes = df['emocao'].tolist()

# Preparar os dados para o Flair
dataset = []
for frase, emocao in zip(frases, emocoes):
    sentence = Sentence(frase)
    sentence.add_label('emocao', emocao)
    dataset.append(sentence)

# Exemplo de uma sentença preparada
print(dataset[0])

# ----------- Treinar ---------------

from flair.data import Corpus
from flair.datasets import FlairDatapointDataset
from flair.models import TextClassifier
from flair.embeddings import WordEmbeddings, DocumentRNNEmbeddings
from flair.trainers import ModelTrainer
from sklearn.utils import shuffle

# Carregar embeddings
word_embeddings = [WordEmbeddings('glove')]

# Definir embeddings do documento com uma RNN
document_embeddings = DocumentRNNEmbeddings(word_embeddings, hidden_size=256, reproject_words=True, reproject_words_dimension=128)

# Aleatorizar
dataset = shuffle(dataset, random_state=42)  # random_state é para garantir reprodutibilidade

# Preparar o dataset para o Flair
train_dataset = FlairDatapointDataset(dataset[:int(0.8 * len(dataset))])
test_dataset = FlairDatapointDataset(dataset[int(0.8 * len(dataset)):])

# Criar o corpus a partir dos datasets
corpus = Corpus(train=train_dataset, test=test_dataset, dev=None)

# Criar o dicionário de rótulos a partir do corpus
label_dictionary = corpus.make_label_dictionary(label_type='emocao')

# Verificar os rótulos
print(label_dictionary)

# Criar o classificador de emoções
classifier = TextClassifier(document_embeddings, label_dictionary=label_dictionary, multi_label=False, label_type='emocao')

# Configurar o trainer
trainer = ModelTrainer(classifier, corpus)

# Decidir hiperparemtros

from flair.trainers import ModelTrainer
import itertools

# Definir as configurações de hiperparâmetros a serem testadas
learning_rates = [0.1]
mini_batch_sizes = [64]
max_epochs = [10]

# Criar todas as combinações possíveis dos hiperparâmetros
param_grid = list(itertools.product(learning_rates, mini_batch_sizes, max_epochs))

# Inicializar variáveis para armazenar os melhores resultados
best_f1_score = 0
best_params = None

# Loop sobre cada combinação de hiperparâmetros
for lr, batch_size, epochs in param_grid:
    print(f"Treinando com lr={lr}, batch_size={batch_size}, epochs={epochs}")
    
    # Treinar o modelo com a combinação atual de hiperparâmetros
    trainer.train(
        base_path=f'modelo_de_emocoes_lr{lr}_bs{batch_size}_ep{epochs}',  # Caminho para salvar o modelo
        learning_rate=lr,
        mini_batch_size=batch_size,
        max_epochs=epochs)
    
    # Avaliar o desempenho do modelo
    result = classifier.evaluate(test_dataset, gold_label_type='emocao')
    
    # Extrair a métrica F1 (ou outra métrica de desempenho)
    f1_score = result.main_score
    
    # Verificar se esta combinação de hiperparâmetros é a melhor até agora
    if f1_score > best_f1_score:
        best_f1_score = f1_score
        best_params = (lr, batch_size, epochs)
    
    print(f"F1 Score: {f1_score}")
    print(f"Melhores parâmetros até agora: {best_params} com F1: {best_f1_score}")

# Exibir os melhores hiperparâmetros ao final da busca
print(f"Melhores hiperparâmetros: lr={best_params[0]}, batch_size={best_params[1]}, epochs={best_params[2]}")



# ------------- Testar -----------------

# # Carregar o modelo treinado
# classifier = TextClassifier.load('modelo_de_emocoes/final-model.pt')

# # Testar com uma nova frase
# nova_frase = Sentence("Estou com medo de apresentar o projeto.")
# classifier.predict(nova_frase)

# # Ver a emoção prevista
# print(nova_frase.labels)


