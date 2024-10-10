<img src="https://upload.wikimedia.org/wikipedia/commons/1/15/Descriptive_Zoopraxography_Athlete%2C_Running_Long_Jump_Animated_14.gif" width="1050" height="300" />


# Análise de Desempenho de Atletas Velocistas

## Descrição

Este programa simula o acompanhamento do desempenho de atletas velocistas ao longo de uma série de treinamentos cronometrados. Ele oferece funcionalidades para exibir a evolução dos tempos, prever o próximo desempenho com base em uma regressão linear simples, além de ordenar e agrupar os atletas por critérios de desempenho. 

O projeto foi desenvolvido em C++ e inclui um menu mostrado no terminal para a navegação entre as diferentes funcionalidades.

## Funcionalidades

O programa apresenta as seguintes opções de menu:

1. **Evolução da Média dos Tempos**: Exibe a evolução da média móvel dos tempos de pelo menos três atletas nos últimos N treinamentos (3 ≤ N ≤ 7).
2. **Agrupamento de Atletas por Desempenho**: Agrupa os atletas que apresentaram melhora, piora ou desempenho estável nos últimos treinamentos, considerando uma variação de 10%.
3. **Ordenação pela Média de Todos os Tempos**: Ordena os atletas com base na média de todos os seus tempos de treinamento.
4. **Ordenação pelos Melhores Resultados da Temporada**: Ordena os atletas com base nos seus melhores tempos em qualquer um dos treinamentos.
5. **Previsão do Tempo do Próximo Treinamento**: Exibe uma previsão do tempo do próximo treino de cada atleta, usando regressão linear simples com base nos dados anteriores.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

- `main.cpp`: Arquivo principal que contém o ponto de entrada do programa e o menu de navegação.
- `atleta.h` / `atleta.cpp`: Definição e implementação da classe `Atleta`, responsável por armazenar e gerenciar os tempos de cada atleta.
- `treinador.h` / `treinador.cpp`: Definição e implementação da classe `Treinador`, que gerencia os atletas e realiza os cálculos relacionados à média móvel, regressão linear, e organização dos dados.
- `Makefile`: Arquivo de automação para a compilação do projeto.
- `README.md`: Instruções de uso e descrição do projeto.

## Compilação e Execução

Para compilar e executar o programa, siga os seguintes passos:

1. **Compilação**:
   Utilize o `Makefile` fornecido para compilar o projeto. No terminal, navegue até o diretório do projeto e execute o comando:
   
   ```bash
   make
   ```

   Isso gerará um executável chamado `velocistas`.

2. **Execução**:
   Após a compilação, o programa pode ser executado com o comando:
   
   ```bash
   make run
   ```

3. **Limpeza**:
   Para limpar os arquivos compilados, você pode utilizar o seguinte comando:
   
   ```bash
   make clean
   ```

## Como Utilizar o Programa

- Ao executar o programa, um menu com várias opções será exibido.
- O usuário deve escolher uma das opções para interagir com os dados dos atletas.
- O programa calculará automaticamente os resultados e exibirá na tela as informações conforme a opção selecionada.

## Observações

- **Média Móvel**: A média móvel é calculada com base nos últimos N treinamentos (3 ≤ N ≤ 7).
- **Previsão com Regressão Linear**: A previsão do próximo tempo de treino é feita utilizando os dados anteriores por meio de um procedimento de regressão linear simples.
- Os tempos de treino são **inicializados diretamente no código**, não havendo necessidade de entrada manual de dados ou leitura de arquivos.


