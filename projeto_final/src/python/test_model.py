from flair.models import TextClassifier
from flair.data import Sentence

# Carregar o modelo salvo
classifier = TextClassifier.load('models/modelo_de_emocoes_lr0.1_bs64_ep10/final-model.pt')

# Frases para testar
nova_frase = Sentence("Hoje eu estou feliz")

# Prever o sentimento da frase
classifier.predict(nova_frase)

# Exibir a previsão
print(nova_frase.labels)  # Retorna o sentimento e a probabilidade associada
