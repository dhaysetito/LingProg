from flair.models import TextClassifier
from flair.data import Sentence

class ModeloEmocoes:
    def __init__(self, caminho_modelo):
        """
        Inicializa o classificador de emoções carregando o modelo salvo.
        """
        self.classificador = TextClassifier.load(caminho_modelo)

    def prever_emocao(self, frase):
        """
        Prediz a emoção de uma frase.
        """
        nova_frase = Sentence(frase)
        self.classificador.predict(nova_frase)
        
        # Extrair o rótulo da emoção e sua probabilidade
        if nova_frase.labels:
            emocao = nova_frase.labels[0].value  # Nome da emoção
            probabilidade = nova_frase.labels[0].score  # Probabilidade (float)
            return emocao, probabilidade
        else:
            return None, 0.0  # Caso não haja rótulos previstos

# Exemplo de uso
if __name__ == "__main__":
    modelo = ModeloEmocoes('models/modelo_de_emocoes_lr0.1_bs64_ep10/best-model.pt')
    emocao, probabilidade = modelo.prever_emocao("Hoje eu estou triste")
    print(f"Emoção: {emocao}, Probabilidade: {probabilidade:.4f}")
