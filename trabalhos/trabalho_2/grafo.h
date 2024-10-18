/**********************************************************
 * Arquivo: grafo.h
 * Descrição: Cabeçalho da classe Grafo
 * Autora: Dhayse de Lima Tito
 **********************************************************/

#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>

#include "aresta.h"
#include "vertice.h"

using namespace std;

// Gerencia a lista de vértices e arestas e oferece os métodos necessários
class Grafo{
    public:
        Grafo ();

        void inserirAresta (Vertice* origem, Vertice* destino, double peso);
        void imprimirMatrizAdj ();
        void imprimirDensidade ();
        void imprimirVerticeMaiorCentralidadeGrau();
        void encontrarMenorCaminho (Vertice* origem, Vertice*destino);
        void imprimirVerticeMaiorCentralidadeProximidade();

        Vertice* procurarVertice(const string& nome);
        
    private:
        vector<Vertice*> vertices;
        vector<Aresta*> arestas;

        list<pair <int, double >>* adj; // Lista de vertices adjacentes de um vertice
        size_t numVertices;

        int encontrarIndiceVertice (Vertice* vertice);
        vector<vector<double>> criarMatrizAdj ();
};

#endif