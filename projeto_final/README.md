# Diário Pessoal com Análise de Emoções

![Python](https://img.shields.io/badge/language-Python-blue?style=for-the-badge&logo=python&logoColor=yellow) ![C++](https://img.shields.io/badge/language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B&logoColor=yellow) ![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)

> Este projeto tem como objetivo desenvolver um **Diário Pessoal** com funcionalidades de **análise emocional** para auxiliar o usuário a compreender e organizar suas emoções ao longo do tempo. O sistema é desenvolvido em **C++** e faz integração com **Python** para a realização de análises de emoções e geração de gráficos e relatórios em PDF.

## 📋 Objetivo do Programa

O sistema permite que o usuário:

- Registre entradas no diário.
- Analise as emoções presentes nas entradas.
- Visualize gráficos de evolução emocional.
- Exclua ou busque entradas por data ou emoção.
- Exporte o diário em formato PDF.

## 📋 Menu de Opções

1. **Registrar Página no Diário**: Adicionar uma nova página com texto e emoções.
2. **Excluir Página do Diário**: Remover uma página selecionada do diário.
3. **Analisar Emoções de uma Entrada**: Processar e exibir as emoções detectadas em uma entrada.
4. **Histórico de Emoções**: Exibir gráficos de evolução emocional com base nas entradas.
5. **Buscar Entrada por Emoção**: Exibir entradas que contêm uma emoção predominante.
6. **Exibir Entradas por Data**: Mostrar entradas em um intervalo de datas.
7. **Exibir Diário Completo**: Exibir todas as entradas registradas no diário.
8. **Exportar Diário em PDF**: Gerar um PDF do diário com todas as entradas ou de um período específico.
9. **Salvar e Sair**: Salvar as alterações e encerrar o programa.

## 🚀 Tecnologias Utilizadas

- **C++**: Utilizado para o gerenciamento do diário, controle do fluxo de dados, e interface com o usuário.
- **Python**: Utilizado para análise de emoções, geração de gráficos e relatórios em PDF.

## 📁 Estrutura do Repositório

> Provável organização - ainda em desenvolvimento

```bash
.
├── src/                 
│   ├── cpp/             # Diretório de código C++
│   │   ├── main.cpp     
│   │   ├── func1.cpp    
│   │   └── func1.h      
│   ├── python/          # Diretório de código Python
│   │   ├── emotions.py  
│   │   ├── pdf_export.py 
│   └── bindings/        # Código para interligação entre C++ e Python
│       ├── py_bind.cpp  
│       └── py_bind.h    
├── tests/               # Testes do projeto
│   ├── cpp/             
│   └── python/          
├── build/               # Arquivos gerados pela compilação C++
│   ├── Makefile         
├── venv/                # Ambiente virtual para dependências Python
├── data/                # Dados de entrada e saída
│   └── diario_data.txt  
│   ├── emocoes_treino.csv 
└── README.md
```

## 🛠️ Requisitos

### Dependências C++:

- **Compilador C++** (GCC ou Clang).
- **Make** (para a compilação).

### Dependências Python:

- **Python 3.x**: Certifique-se de ter o Python 3.x instalado em seu sistema.
- **Ambiente Virtual Python** (recomendado): Use um ambiente virtual para gerenciar as dependências de Python sem conflitos.

### Instalação das Dependências Python:

1. **Criar o Ambiente Virtual**:

   Se você ainda não tiver um ambiente virtual Python, crie um com o seguinte comando:

   ```bash
   python3 -m venv venv
   ```

2. **Ativar o Ambiente Virtual**:

   - **No Linux/Mac**:

     ```bash
     source venv/bin/activate
     ```

   - **No Windows**:

     ```bash
     .\venv\Scripts\activate
     ```

3. **Instalar as Dependências Python**:

   Após ativar o ambiente virtual, instale as dependências necessárias com o seguinte comando:

   ```bash
   pip install -r requirements.txt
   ```

## 🛠️ Ajustes e Melhorias

O projeto ainda está em desenvolvimento.

## 🛠️ Como Executar

1. **Compilação**:
   Utilize o `Makefile` fornecido para compilar o projeto. No terminal, navegue até o diretório do projeto e execute o comando:
   
   ```bash
   make
   ```

   Isso gerará um executável chamado `Divertidamente`.

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

4. As funções de análise emocional e exportação de PDF serão executadas através das chamadas para os scripts Python.

## 📄 Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo [LICENSE](./LICENSE) para mais informações.
