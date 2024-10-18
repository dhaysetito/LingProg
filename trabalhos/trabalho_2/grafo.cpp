#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

#include "grafo.h"

using namespace std;

#define INFINITO numeric_limits<int>::max()

// Inicia contrutor
Grafo::Grafo() {
    numVertices = 0; 
    adj = nullptr; 
}

// Insere uma aresta entre dois vértices
void Grafo::inserirAresta(Vertice* origem, Vertice* destino, double peso) {
    // Verifica se o vértice de origem já está no grafo
    int idxOrigem = encontrarIndiceVertice(origem);
    if (idxOrigem == -1) {
        vertices.push_back(origem);
        idxOrigem = vertices.size() - 1;  
    }

    // Verifica se o vértice de destino já está no grafo
    int idxDestino = encontrarIndiceVertice(destino);
    if (idxDestino == -1) {
        vertices.push_back(destino);
        idxDestino = vertices.size() - 1;
    }

    // Realoque a lista de adjacências com o novo número de vértices, se necessário
    if (adj == nullptr) {
        adj = new list<pair<int, double>>[vertices.size()];  
    } else if (vertices.size() > numVertices) {
        // Redimensiona a lista de adjacências para incluir os novos vértices
        list<pair<int, double>>* novaAdj = new list<pair<int, double>>[vertices.size()];
        
        // Copia as listas anteriores
        for (size_t i = 0; i < numVertices; i++) {
            novaAdj[i] = adj[i];
        }

        delete[] adj;  // Libera a antiga lista
        adj = novaAdj;  // Atualiza o ponteiro de adj
    }

    // Atualiza o número de vértices após inserção
    numVertices = vertices.size();

    // Adiciona as arestas na lista de adjacências (grafo não-direcionado)
    adj[idxOrigem].push_back(make_pair(idxDestino, peso));
    adj[idxDestino].push_back(make_pair(idxOrigem, peso));

    // Cria uma nova aresta e adiciona ao vetor de arestas
    Aresta* novaAresta = new Aresta(origem, destino, peso);  // Supondo que Aresta tenha um construtor que recebe dois vértices e o peso
    arestas.push_back(novaAresta); 


    // Verifica se a aresta foi encontrada
    //cout << novaAresta->getPrimeiroVertice()->getRotulo() << " e " << novaAresta->getSegundoVertice()->getRotulo() << " com peso " << novaAresta->getPeso() << endl;
    
}


// Encontra o índice do vértice
int Grafo::encontrarIndiceVertice(Vertice* vertice) {
    for (size_t i = 0; i < vertices.size(); i++) {
        if (vertices[i]->getRotulo() == vertice->getRotulo()) {
            return i;
        }
    }

    return -1;  // Caso não seja encontrado
}

// Procura o vertice a partir da string
Vertice* Grafo::procurarVertice(const string& nome) {
    for (Vertice* v : vertices) {
        if (v->getRotulo() == nome) {
            return v; 
        }
    }
    return nullptr;
}

// Cria e retorna a matriz de adjacência
vector<vector<double>> Grafo::criarMatrizAdj() {
    vector<vector<double>> matriz(numVertices, vector<double>(numVertices, 0));
    
    for (Aresta* aresta : arestas) {
        cout << "Teste" << endl;
        int indiceOrigem = encontrarIndiceVertice(aresta->getPrimeiroVertice());
        int indiceDestino = encontrarIndiceVertice(aresta->getSegundoVertice());
        matriz[indiceOrigem][indiceDestino] = aresta->getPeso();
        matriz[indiceDestino][indiceOrigem] = aresta->getPeso(); 
    }

    return matriz;
}

// Imprime matriz de adjacência
void Grafo::imprimirMatrizAdj() {
    vector<vector<double>> matriz = criarMatrizAdj();

    for (size_t i = 0; i < matriz.size(); i++) {
        for (size_t j = 0; j < matriz[i].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Calcula e imprime densidade do grafo
void Grafo::imprimirDensidade() {
    int numArestas = arestas.size();

    // Fórmula para a densidade: (2 * número de arestas) / (número de vértices * (número de vértices - 1))
    double densidade = (2.0 * numArestas) / (numVertices * (numVertices - 1));
    cout << "Densidade do grafo: " << densidade << endl;
}

void Grafo::imprimirVerticeMaiorCentralidadeGrau() {
    double maiorGrau = -1;
    Vertice* verticeMaiorGrau = nullptr;

    // Itera sobre todos os vértices
    for (size_t i = 0; i < vertices.size(); i++) {
        double grauAtual = 0;

        // Soma os pesos das arestas conectadas a esse vértice
        for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
            grauAtual += it->second;
        }

        // Verifica se este vértice tem o maior grau
        if (grauAtual > maiorGrau) {
            maiorGrau = grauAtual;
            verticeMaiorGrau = vertices[i];
        }
    }

    if (verticeMaiorGrau != nullptr) {
        cout << "Vértice com maior centralidade de grau: " << verticeMaiorGrau->getRotulo() << endl;
        cout << "Grau: " << maiorGrau << endl;
    }
}


// Algoritmo de Dijkstra
void Grafo::encontrarMenorCaminho(Vertice* origem, Vertice* destino) {
    // Vetor de distâncias
    vector<int> dist(numVertices, INFINITO);

    // Vetor de visitados
    vector<bool> visitados(numVertices, false);

    // Vetor de predecessores para reconstruir o caminho
    vector<int> predecessores(numVertices, -1);  // Inicialmente todos predecessores são -1

    // Fila de prioridades de pair (distância, vértice)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int idxOrigem = encontrarIndiceVertice(origem);
    int idxDestino = encontrarIndiceVertice(destino);

    // A distância da origem para a origem é 0
    dist[idxOrigem] = 0;

    // Insere a origem na fila de prioridades
    pq.push(make_pair(dist[idxOrigem], idxOrigem));

    // Loop do algoritmo
    while (!pq.empty()) {
        pair<int, int> p = pq.top();  // Extrai o pair do topo
        int u = p.second;  // Obtém o vértice do pair
        pq.pop();  // Remove da fila

        // Verifica se o vértice não foi expandido
        if (!visitados[u]) {
            // Marca como visitado
            visitados[u] = true;

            // Percorre os vértices adjacentes de "u"
            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                // Obtém o vértice adjacente e o custo da aresta
                int v = it->first;
                int custo_aresta = it->second;

                // Relaxamento (u, v)
                if (dist[v] > dist[u] + custo_aresta) {
                    // Atualiza a distância de "v" e insere na fila
                    dist[v] = dist[u] + custo_aresta;
                    predecessores[v] = u;  // Atualiza o predecessor de v
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    // Se o destino não foi alcançado
    if (dist[idxDestino] == INFINITO) {
        cout << "Não há caminho entre " << origem->getRotulo() << " e " << destino->getRotulo() << endl;
        return;
    }

    // Imprimir o custo total do caminho
    cout << "Custo total do caminho: " << dist[idxDestino] << endl;

    // Reconstruir e imprimir o caminho
    vector<int> caminho;
    for (int v = idxDestino; v != -1; v = predecessores[v]) {
        caminho.push_back(v);
    }
    reverse(caminho.begin(), caminho.end());  // Inverter o caminho para exibir da origem ao destino

    // Imprimir a sequência de vértices no caminho
    cout << "Caminho: ";
    for (size_t i = 0; i < caminho.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << vertices[caminho[i]]->getRotulo();
    }
    cout << endl;
}

// Imprime vertice de maior centralidade por proximidade
void Grafo::imprimirVerticeMaiorCentralidadeProximidade() {
    // Variáveis para armazenar o vértice com maior centralidade de proximidade e o valor dessa centralidade
    Vertice* verticeMaiorCentralidade = nullptr;
    double maiorCentralidade = 0.0;

    // Iterar sobre todos os vértices
    for (Vertice* vertice : vertices) {
        // Vetor de distâncias, inicializado com INFINITO para todos os vértices
        vector<int> dist(numVertices, INFINITO);

        // Vetor de visitados
        vector<bool> visitados(numVertices, false);

        // Fila de prioridades (distância, vértice)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int idxOrigem = encontrarIndiceVertice(vertice);

        // A distância do vértice para ele mesmo é 0
        dist[idxOrigem] = 0;

        // Insere o vértice de origem na fila de prioridades
        pq.push(make_pair(dist[idxOrigem], idxOrigem));

        // Loop do algoritmo de Dijkstra para calcular as menores distâncias
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            int u = p.second;
            pq.pop();

            if (!visitados[u]) {
                visitados[u] = true;

                for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                    int v = it->first;
                    int custo_aresta = it->second;

                    if (dist[v] > dist[u] + custo_aresta) {
                        dist[v] = dist[u] + custo_aresta;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }

        // Somar as distâncias mínimas para todos os outros vértices
        double somaDistancias = 0.0;
        int countAcessiveis = 0;  // Contador para vértices alcançáveis
        for (int d : dist) {
            if (d != INFINITO) {
                somaDistancias += d;
                countAcessiveis++;
            }
        }

        // Verifica se o vértice alcança pelo menos um outro vértice
        if (countAcessiveis > 1) {  // Exclui o próprio vértice
            double centralidadeProximidade = (double)(countAcessiveis - 1) / somaDistancias;

            // Atualiza o vértice com maior centralidade se necessário
            if (centralidadeProximidade > maiorCentralidade) {
                maiorCentralidade = centralidadeProximidade;
                verticeMaiorCentralidade = vertice;
            }
        }
    }

    // Imprimir o vértice com maior centralidade de proximidade
    if (verticeMaiorCentralidade != nullptr) {
        cout << "Vértice com maior centralidade de proximidade: " << verticeMaiorCentralidade->getRotulo()
             << " com valor de centralidade: " << maiorCentralidade << endl;
    } else {
        cout << "Não foi possível determinar a centralidade de proximidade para os vértices." << endl;
    }
}
