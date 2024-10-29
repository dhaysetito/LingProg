<img src="image.png" width="1050" height="300" alt="Grafo imagem" />


# Análise de Desempenho de Atletas Velocistas

## Descrição

Este projeto implementa uma classe para representar um caminho em grafos simétricos, utilizando classes para os vértices e arestas. Um caminho é definido como uma sequência de vértices conectados por arestas, cada uma com um peso associado. O projeto inclui funcionalidades para a criação de vértices e arestas, inserção de arestas em um caminho, e cálculo do custo total do caminho.

O projeto foi desenvolvido em C++ e inclui um menu mostrado no terminal para a navegação entre as diferentes funcionalidades.

## Funcionalidades

O programa apresenta as seguintes opções de menu:

1. **Inserir vértice no caminho:**
   - Insere uma nova aresta no caminho, verificando se o vértice inicial da nova aresta coincide com o vértice final do caminho atual. Caso contrário, a inserção não é realizada.

2. **Exibir caminho e custo total:**
   - Imprime o caminho na tela, exibindo a sequência de vértices conectados pelas arestas e o peso total (custo) do caminho, que é a soma dos pesos de todas as arestas.

3. **Calcular distância do caminho:**
   - Calcula e retorna a distância total (custo) do caminho, somando os pesos de todas as arestas presentes no caminho.

4. **Validar continuidade do caminho:**
   - Verifica se uma aresta pode ser inserida no caminho, garantindo que a continuidade do caminho seja respeitada (o vértice inicial da nova aresta deve ser o mesmo que o vértice final da última aresta).

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

- **vertice.h**: Definição da classe `Vertice`, que representa um vértice do grafo.
- **vertice.cpp**: Implementação dos métodos da classe `Vertice`.
- **aresta.h**: Definição da classe `Aresta`, que representa uma aresta conectando dois vértices com seus respectivos pesos.
- **aresta.cpp**: Implementação dos métodos da classe `Aresta`.
- **grafo.h**: Definição da classe `Grafo`, que representa um grafo com vertices e arestas.
- **grafo.cpp**: Implementação dos métodos da classe `Grafo`.
- **main.cpp**: Programa principal que demonstra o funcionamento da criação e manipulação de caminhos em grafos.

## Compilação e Execução

Para compilar e executar o programa, siga os seguintes passos:

1. **Compilação**:
   Utilize o `Makefile` fornecido para compilar o projeto. No terminal, navegue até o diretório do projeto e execute o comando:
   
   ```bash
   make
   ```

   Isso gerará um executável chamado `programa`.

2. **Execução**:
   Após a compilação, o programa pode ser executado com o comando:
   
   ```bash
   make run "grafo.txt"
   ```

   > `"grafo.txt"` pode ser substituído por nome de outro arquivo. 

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


