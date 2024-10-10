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

1. **Registrar Entrada no Diário**: Adicionar uma nova entrada com texto e emoções.
2. **Excluir Entrada do Diário**: Remover uma entrada selecionada.
3. **Analisar Emoções de uma Entrada**: Processar e exibir as emoções detectadas em uma entrada.
4. **Histórico de Emoções**: Exibir gráficos de evolução emocional.
5. **Buscar Entrada por Emoção**: Exibir entradas com uma emoção predominante.
6. **Exibir Entradas por Data**: Mostrar entradas em um intervalo de datas.
7. **Exportar Diário em PDF**: Gerar um PDF do diário com todas as entradas ou de um período específico.

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
