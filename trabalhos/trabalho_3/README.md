# Programa de Histórico Acadêmico com Cálculo de CRA

## Descrição
Este é um programa desenvolvido para gerenciar o histórico acadêmico de um estudante, incluindo o cálculo do Coeficiente de Rendimento Acadêmico (CRA) e a persistência dos dados em um arquivo de texto. O sistema permite a inserção, remoção e visualização de disciplinas, além de alterar notas e buscar disciplinas por período. Os dados podem ser salvos em um arquivo para persistência entre sessões.

### Funcionalidades:
- Imprimir o histórico completo de disciplinas.
- Imprimir informações de uma disciplina específica.
- Inserir uma nova disciplina no histórico.
- Remover uma disciplina do histórico.
- Buscar disciplinas por período.
- Alterar a nota de uma disciplina.
- Calcular o CRA (Coeficiente de Rendimento Acadêmico) do aluno.
- Persistir os dados em um arquivo de texto (`disciplinas.txt`).

## Estrutura de Arquivos
O programa é composto pelos seguintes arquivos:

- **`main.cpp`**: Arquivo principal onde a execução do programa ocorre. Contém a interface de linha de comando e as interações com o usuário.
- **`historico.cpp`**: Implementação da classe `Historico`, que gerencia o histórico acadêmico do aluno, incluindo inserção, remoção e busca de disciplinas.
- **`historico.h`**: Cabeçalho da classe `Historico` que define a estrutura e os métodos da classe.
- **`disciplina.cpp`**: Implementação da classe `Disciplina`, que representa uma disciplina acadêmica.
- **`disciplina.h`**: Cabeçalho da classe `Disciplina`, que define a estrutura e os métodos da classe.
- **`Makefile`**: Arquivo de build que permite compilar o programa de maneira eficiente.
- **`README.md`**: Arquivo de documentação do projeto.

## Como Usar
1. Clone ou faça o download do repositório.
2. Abra o terminal e navegue até o diretório onde os arquivos estão armazenados.
3. Compile o programa utilizando o comando:
   ```bash
   make
   ```
4. Execute o programa:
   ```bash
   make run 
   ```
5. Siga as instruções no menu para interagir com o programa.

### Menu de Opções:
1. **Imprimir histórico de disciplinas**: Exibe todas as disciplinas do histórico.
2. **Imprimir uma disciplina**: Exibe os detalhes de uma disciplina especificada pelo nome.
3. **Inserir uma disciplina**: Permite adicionar uma nova disciplina ao histórico.
4. **Remover disciplina**: Remove uma disciplina do histórico.
5. **Buscar disciplinas por período**: Exibe as disciplinas de um período específico.
6. **Alterar nota**: Permite alterar a nota de uma disciplina.
7. **Calcular CRA**: Calcula e exibe o Coeficiente de Rendimento Acadêmico (CRA).
8. **Salvar e sair**: Salva as alterações e encerra o programa.

## Dependências
O programa foi desenvolvido em C++ e usa as bibliotecas padrão de entrada e saída (`iostream`), manipulação de strings (`string`), leitura de arquivos (`fstream`), e containers de dados (`vector`, `map`).

## Compilação
Este projeto utiliza o `Makefile` para automação da compilação. Para compilar o projeto, basta executar o comando `make` no terminal.

 
## Licença
Este projeto está licenciado sob a Licença MIT. Veja o arquivo LICENSE para mais detalhes.

