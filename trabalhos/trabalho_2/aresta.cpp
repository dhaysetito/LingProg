/**********************************************************
 * Arquivo: aresta.cpp
 * Descrição: Implementação da classe Aresta -
 *            Representa uma aresta com dois vértices e um peso.
 * Autora: Dhayse de Lima Tito
 **********************************************************/

#include "aresta.h"

// Construtor da classe Aresta
Aresta::Aresta(Vertice* primeiro, Vertice* segundo, double peso) {
    this->verticeOrigem = primeiro;
    this->verticeDestino = segundo;
    this->peso = peso;
}

// Retorna o vértice de origem
Vertice* Aresta::getVerticeOrigem() {
    return verticeOrigem;
}

// Retorna o vértice de destino
Vertice* Aresta::getVerticeDestino() {
    return verticeDestino;
}

// Retorna o peso da aresta
double Aresta::getPeso() {
    return peso;
}
