#include <iostream>
#include <limits> 

#include "atleta.h"
#include "treinador.h"

using namespace std;

void mostrarMenu() {
    cout << "Menu:\n";
    cout << "1. Exibir evolução da média dos tempos dos atletas\n";
    cout << "2. Exibir atletas com melhoria ou piora de desempenho\n";
    cout << "3. Ordenar atletas por média de todos os tempos\n";
    cout << "4. Ordenar atletas por melhores resultados da temporada\n";
    cout << "5. Prever o tempo do próximo treino\n";
    cout << "6. Sair\n\n";
}

// Aguarda 'Enter' antes de continuar
void esperarEnter() {
    cout << "\nPressione Enter para continuar...\n";
    while (cin.get() != '\n'); // Limpa o buffer
    cin.get();  // Espera o usuário pressionar Enter
}

int main() {
    // Cria alguns atletas arbitrários com seus tempos de treino
    Atleta atleta1("Atleta A", {12.5, 11.8, 11.9, 10.5, 10, 10.1, 10, 10.1});
    Atleta atleta2("Atleta B", {10.2, 10.4, 10, 4});
    Atleta atleta3("Atleta C", {11.0, 11.1, 10.9});
    Atleta atleta4("Atleta D", {10.9, 10.5, 10.6, 10.1, 10.2});

    // Cria o treinador e associar os atletas
    Treinador treinador;
    treinador.adicionarAtleta(atleta1);
    treinador.adicionarAtleta(atleta2);
    treinador.adicionarAtleta(atleta3);
    treinador.adicionarAtleta(atleta4);

    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                treinador.exibirEvolucaoMedia();
                break;
            case 2:
                treinador.exibirMelhoriaDesempenho();
                break;
            case 3:
                treinador.ordenarAtletasPorMedia();
                break;
            case 4:
                treinador.ordenarAtletasPorMelhorTempo();
                break;
            case 5:
                treinador.preverProximoTempo();
                break;
            case 6:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

        if (opcao != 6) {
            esperarEnter();
        }

    } while (opcao != 6);

    return 0;
}