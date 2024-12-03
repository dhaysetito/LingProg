/**********************************************************
 * Universidade Federal do Rio de Janeiro (UFRJ)
 * Disciplina: Linguagens de Programação
 * Professor: Miguel Campista
 *
 * Arquivo: main.cpp
 * Versão: 2.0
 * Data de Criação: 28/10/2024
 * Última Modificação: 22/11/2024
 *
 * Descrição: 
 * Programa que implementa um historico de discplina com
 * calculo de CRA e salvamento num txt
 **********************************************************
 * Autora: Dhayse de Lima Tito
 * E-mail: dhayse@poli.ufrj.br
 **********************************************************/

#include <iostream>
#include <string>
#include <limits>
#include "historico.h"

using namespace std;

// Aguarda 'Enter' antes de continuar
void esperarEnter() {
    cout << "\nPressione Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora qualquer entrada residual no buffer
    cin.get();  // Espera o usuário pressionar Enter
}

void mostrarMenu() {
    cout << "\nMenu de Opções:" << endl;
    cout << "1. Imprimir histórico de disciplinas" << endl;
    cout << "2. Imprimir uma disciplina" << endl;
    cout << "3. Inserir uma disciplina" << endl;
    cout << "4. Remover disciplina" << endl;
    cout << "5. Buscar disciplinas por período" << endl;
    cout << "6. Alterar nota" << endl;
    cout << "7. Calcular CRA" << endl;
    cout << "8. Salvar e sair" << endl;
    cout << "Escolha uma opção: ";
}

int main() {
    Historico historico("disciplinas.txt");
    CRA cra;
    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "\nHistórico de Disciplinas:\n" << historico;
                break;
            case 2: {
                string nome;
                cout << "Digite o nome da disciplina: ";
                cin >> nome;
                Disciplina* d = historico.buscarDisciplina(nome);
                if (d) cout << *d << endl;
                else cout << "Disciplina não encontrada." << endl;
                break;
            }
            case 3: {
                Disciplina d;
                cin >> d;
                if ((historico += d) == -1){
                   cout << "Disciplina já existente no histórico." << endl; 
                } else {
                    cout << "Disciplina inserida com sucesso!" << endl;
                }
                break;
            }
            case 4: {
                string nome;
                cout << "Digite o nome da disciplina: ";
                cin >> nome;
                Disciplina d{nome, "", 0, 0.0};
                if ((historico -= d) == -1) cout << "Erro ao remover disciplina." << endl;
                else cout << "Disciplina removida com sucesso!" << endl;
                break;
            }
            case 5: {
                string periodo;
                cout << "Digite o período: ";
                cin >> periodo;
                auto disciplinas = historico(periodo);
                for (const auto& d : disciplinas) cout << d << endl;
                break;
            }
            case 6: {
                string nome;
                double novaNota;
                cout << "Digite o nome da disciplina: ";
                cin >> nome;
                cout << "Digite a nova nota: ";
                cin >> novaNota;
                try {
                    historico[nome] = novaNota;
                    cout << "Nota alterada com sucesso!" << endl;
                } catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 7:
                historico >> cra;
                cra.exibirCRA();
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
    } while (opcao != 8);

    return 0;
}
