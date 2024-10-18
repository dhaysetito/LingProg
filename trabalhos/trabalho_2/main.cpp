/**********************************************************
 * Universidade Federal do Rio de Janeiro (UFRJ)
 * Disciplina: Linguagens de Programação
 * Professor: Miguel Campista
 *
 * Arquivo: main.cpp
 * Versão: 2.0
 * Data de Criação: 15/10/2024
 * Última Modificação: 18/10/2024
 *
 * Descrição: 
 * Programa que implementa um grafo  a partir de um 
 * arquivo txt. Possui funcionalidades que são escolhidas 
 * de um menu.
 **********************************************************
 * Autora: Dhayse de Lima Tito
 * E-mail: dhayse@poli.ufrj.br
 **********************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "grafo.h"

using namespace std;

void carregarGrafoDeArquivo(Grafo& grafo, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string linha;

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    while (getline(arquivo, linha)) {
        // Ignora linhas de comentários que começam com '#'
        if (linha[0] == '#') continue;

        string vertice1, vertice2;
        double peso;

        // Usa um stream para separar a linha em vértices e pesos
        stringstream ss(linha);
        ss >> vertice1 >> vertice2 >> peso;

        // Procura se os vértices já existem no grafo
        Vertice* v1 = grafo.procurarVertice(vertice1);
        if (v1 == nullptr) {
            v1 = new Vertice(vertice1);  
        }

        Vertice* v2 = grafo.procurarVertice(vertice2);
        if (v2 == nullptr) {
            v2 = new Vertice(vertice2);  
        }

        // Insere a aresta entre os vértices v1 e v2
        grafo.inserirAresta(v1, v2, peso);

        //cout << "Aresta inserida: " << vertice1 << " " << vertice2 << " " << peso << endl;
    }

    arquivo.close();
}


void mostrarMenu() {
    cout << "Menu de Opções:" << endl;
    cout << "1. Imprimir Matriz de Adjacência" << endl;
    cout << "2. Imprimir Densidade do Grafo" << endl;
    cout << "3. Imprimir o vértice com a maior centralidade de grau" << endl;
    cout << "4. Encontrar o menor caminho (Dijkstra)" << endl;
    cout << "5. Imprimir o vértice com a maior centralidade de proximidade" << endl;
    cout << "6. Sair" << endl;
    cout << "Escolha uma opção: ";
}

// Aguarda 'Enter' antes de continuar
void esperarEnter() {
    cout << "\nPressione Enter para continuar...\n";
    while (cin.get() != '\n'); // Limpa o buffer
    cin.get();  // Espera o usuário pressionar Enter
}

int main(int argc, char* argv[]) {
    Grafo grafo;

    if (argc < 2) {
        cout << "Por favor, forneça o nome do arquivo como argumento." << endl;
        return 1;
    }

    string nomeArquivo = argv[1];
    carregarGrafoDeArquivo(grafo, nomeArquivo);

    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Matriz de Adjacência:" << endl;
                grafo.imprimirMatrizAdj();
                break;
            case 2:
                grafo.imprimirDensidade();
                break;
            case 3:
                cout << "Vértice com maior centralidade de grau: " << endl;
                grafo.imprimirVerticeMaiorCentralidadeGrau();
                break;
            case 4: {
                string origem, destino;
                cout << "Digite o vértice de origem: ";
                cin >> origem;
                cout << "Digite o vértice de destino: ";
                cin >> destino;

                Vertice* verticeOrigem = grafo.procurarVertice(origem);
                Vertice* verticeDestino = grafo.procurarVertice(destino);

                if (verticeOrigem == nullptr || verticeDestino == nullptr) {
                    cout << "Um ou ambos os vértices não foram encontrados no grafo." << endl;
                } else {
                    grafo.encontrarMenorCaminho(verticeOrigem, verticeDestino);
                }
                break;
            }
            case 5:
                cout << "Vértice com maior centralidade de proximidade: " << endl;
                grafo.imprimirVerticeMaiorCentralidadeProximidade();
                break;
            case 6:
                break;
            default:
                cout << "Opção inválida, tente novamente." << endl;
                break;
        }
        if (opcao != 6) {
            esperarEnter();
        }
    }while (opcao != 6);
    

    cout << "Programa finalizado." << endl;
    return 0;
}
