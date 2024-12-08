/**********************************************************
 * Universidade Federal do Rio de Janeiro (UFRJ)
 * Disciplina: Linguagens de Programação
 * Professor: Miguel Campista
 *
 * Arquivo: main.cpp
 * Versão: 1.0
 * Data de Criação: 24/10/2024
 * Última Modificação: 07/12/2024
 *
 * Descrição: 
 * Programa que cria um diário e analisa as emoções 
 **********************************************************
 * Autora: Dhayse de Lima Tito
 * E-mail: dhayse@poli.ufrj.br
 **********************************************************/

#include <iostream>
#include <string>
#include <limits>
#include <pybind11/embed.h>

namespace py = pybind11;

#include "../include/diario.h"

// Aguarda 'Enter' antes de continuar
void esperarEnter() {
    std::cout << "\nPressione Enter para continuar...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignora qualquer entrada residual no buffer
    std::cin.get();  // Espera o usuário pressionar Enter
}

void mostrarMenu() {
    std::cout << "\nMenu de Opções:" << std::endl;
    std::cout << "1. Registrar Página no Diário" << std::endl;
    std::cout << "2. Excluir Página do Diário" << std::endl;
    std::cout << "3. Analisar Emoções de uma Entrada" << std::endl;
    std::cout << "4. Exibir Entradas por Data" << std::endl;
    std::cout << "5. Exibir Diário Completo" << std::endl;
    std::cout << "6. Salvar e sair" << std::endl;
    std::cout << "Escolha uma opção: ";
}

int main() {

    auto dataCriacao = std::chrono::system_clock::now();
    std::string nomeDono;
    std::cout << "\n------------------------------------------\nA quem pertence esse Diário? ";
    getline(std::cin, nomeDono);

    Diario diario(nomeDono, dataCriacao);

    diario.iniciarDiario(nomeDono);

    int opcao;
    std::string dataStr;
    std::string conteudo;
    std::pair<std::string, float> resultado;

    // Inicializa o interpretador Python
    py::scoped_interpreter guard{};

    do {
        mostrarMenu();
        std::cin >> opcao;

        if (std::cin.fail()) { // Verificar se a entrada foi inválida
            std::cout << "\nErro: por favor, insira apenas números inteiros." << std::endl;
            std::cin.clear(); // Limpar estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar o buffer
        } else {
            switch (opcao) {
                case 1:
                    // Recebe a data
                    std::cout << "\nDigite a data (dd/mm/aaaa): ";
                    std::cin.ignore();  // Limpar o buffer do std::cin
                    getline(std::cin, dataStr);

                    // Recebe o conteudo
                    std::cout << "\nDigite o conteúdo da página: ";
                    getline(std::cin, conteudo);

                    try {
                            // Criar a página com a data convertida
                            Pagina novaPagina(0, std::chrono::system_clock::now(), conteudo); // O número da página será atribuído depois

                            // Usar setData para atribuir a data convertida
                            novaPagina.setData(dataStr);  // Converte a string para o tipo de data correto

                            // Adicionar a página no diário
                            diario.adicionarPagina(novaPagina.getData(), conteudo);
                            std::cout << "Página registrada com sucesso!" << std::endl;

                        } catch (const std::invalid_argument& e) {
                            std::cout << "Erro: " << e.what() << std::endl;
                        }
                    break;
                case 2:
                    std::cout << "Informe a data (dd/mm/aaaa): ";
                    std::cin.ignore();
                    getline(std::cin, dataStr);
                    try{
                        diario.excluirPagina(diario.stringParaData(dataStr));
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Erro: " << e.what() << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "Informe a data (dd/mm/aaaa): ";
                    std::cin.ignore();
                    getline(std::cin, dataStr);
                    resultado = diario.analisarPaginaEmocao(diario.stringParaData(dataStr));

                    if (resultado.first != "Erro"){
                        std::cout << "Emoção: " << resultado.first << std::endl;
                        std::cout << "Probabilidade: " << resultado.second << std::endl;
                    };
                    break;
                case 4:
                    std::cout << "Informe a data (dd/mm/aaaa): ";
                    std::cin.ignore();
                    getline(std::cin, dataStr);
                    try{
                       diario.imprimirPaginaPorData(diario.stringParaData(dataStr)); 
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Erro: " << e.what() << std::endl;
                    }
                    
                    break;
                case 5:
                    diario.imprimirTudo();
                    break;
                case 6:
                    diario.salvarDiario();
                    std::cout << "Encerrando o programa..." << std::endl;
                    break;
                default:
                    std::cout << "Opção inválida." << std::endl;
                    break;
            }
            if (opcao != 6) {
                esperarEnter();
            }
        }
    } while (opcao != 6);

    return 0;
}