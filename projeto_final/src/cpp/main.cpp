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
    cout << "\nPressione Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora qualquer entrada residual no buffer
    cin.get();  // Espera o usuário pressionar Enter
}

void mostrarMenu() {
    cout << "\nMenu de Opções:" << endl;
    cout << "1. Registrar Entrada no Diário" << endl;
    cout << "2. Excluir Entrada do Diário" << endl;
    cout << "3. Analisar Emoções de uma Entrada" << endl;
    cout << "4. Histórico de Emoções" << endl;
    cout << "5. Buscar Entrada por Emoção" << endl;
    cout << "6. Exibir Entradas por Data" << endl;
    cout << "7. Exportar Diário em PDF" << endl;
    cout << "8. Salvar e sair" << endl;
    cout << "Escolha uma opção: ";
}

int main() {
    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        if (cin.fail()) { // Verificar se a entrada foi inválida
            cout << "\nErro: por favor, insira apenas números inteiros." << endl;
            cin.clear(); // Limpar estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar o buffer
        } else {
            switch (opcao) {
                case 1:
                    cout << "\nImprimir diário:\n";
                    break;
                case 8:
                    cout << "Encerrando o programa..." << endl;
                    break;
                default:
                    cout << "Opção inválida." << endl;
                    break;
            }
            if (opcao != 8) {
                esperarEnter();
            }
        }
    } while (opcao != 8);

    return 0;
}