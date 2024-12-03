/**********************************************************
 * Universidade Federal do Rio de Janeiro (UFRJ)
 * Disciplina: Linguagens de Programação
 * Professor: Miguel Campista
 *
 * Arquivo: main.cpp
 * Versão: 1.0
 * Data de Criação: 24/10/2024
 * Última Modificação: 02/12/2024
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

#include "../include/diario.h"

using namespace std;

// Aguarda 'Enter' antes de continuar
void esperarEnter() {
    std::cout << "\nPressione Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora qualquer entrada residual no buffer
    cin.get();  // Espera o usuário pressionar Enter
}

void mostrarMenu() {
    std::cout << "\nMenu de Opções:" << endl;
    std::cout << "1. Registrar Página no Diário" << endl;
    std::cout << "2. Excluir Página do Diário" << endl;
    std::cout << "3. Analisar Emoções de uma Entrada" << endl;
    std::cout << "4. Histórico de Emoções" << endl;
    std::cout << "5. Buscar Entrada por Emoção" << endl;
    std::cout << "6. Exibir Entradas por Data" << endl;
    std::cout << "7. Exibir Diário Completo" << endl;
    std::cout << "8. Exportar Diário em PDF" << endl;
    std::cout << "9. Salvar e sair" << endl;
    std::cout << "Escolha uma opção: ";
}

int main() {

    auto dataCriacao = std::chrono::system_clock::now();
    std::string nomeDono;
    std::cout << "\n------------------------------------------\nA quem pertence esse Diário? ";
    getline(cin, nomeDono);

    Diario diario(nomeDono, dataCriacao);

    diario.iniciarDiario(nomeDono);

    int opcao;
    string dataStr;
    string conteudo;

    do {
        mostrarMenu();
        cin >> opcao;

        if (cin.fail()) { // Verificar se a entrada foi inválida
            std::cout << "\nErro: por favor, insira apenas números inteiros." << endl;
            cin.clear(); // Limpar estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar o buffer
        } else {
            switch (opcao) {
                case 1:
                    // Recebe a data
                    std::cout << "\nDigite a data (dd/mm/aaaa): ";
                    cin.ignore();  // Limpar o buffer do cin
                    getline(cin, dataStr);

                    // Recebe o conteudo
                    std::cout << "\nDigite o conteúdo da página: ";
                    getline(cin, conteudo);

                    try {
                            // Criar a página com a data convertida
                            Pagina novaPagina(0, std::chrono::system_clock::now(), conteudo); // O número da página será atribuído depois

                            // Usar setData para atribuir a data convertida
                            novaPagina.setData(dataStr);  // Converte a string para o tipo de data correto

                            // Adicionar a página no diário
                            diario.adicionarPagina(novaPagina.getData(), conteudo);
                            std::cout << "Página registrada com sucesso!" << endl;

                        } catch (const std::invalid_argument& e) {
                            std::cout << "Erro: " << e.what() << endl;
                        }
                    break;
                case 2:
                    std::cout << "Informe a data (dd/mm/aaaa): " << endl;
                    cin.ignore();
                    getline(cin, dataStr);
                    diario.excluirPagina(diario.stringParaData(dataStr));
                    break;
                case 6:
                    std::cout << "Informe a data (dd/mm/aaaa): " << endl;
                    cin.ignore();
                    getline(cin, dataStr);
                    diario.imprimirPaginaPorData(diario.stringParaData(dataStr));
                    break;
                case 7:
                    //std::cout << "\nImprimir diário:\n" << endl;
                    diario.imprimirTudo();
                    break;
                case 9:
                    diario.salvarDiario();
                    std::cout << "Encerrando o programa..." << endl;
                    break;
                default:
                    std::cout << "Opção inválida." << endl;
                    break;
            }
            if (opcao != 9) {
                esperarEnter();
            }
        }
    } while (opcao != 9);

    return 0;
}