#include "aresta.h"

// Construtor da classe Aresta
Aresta::Aresta(Vertice* primeiro, Vertice* segundo, double peso) {
    this->primeiroVertice = primeiro;
    this->segundoVertice = segundo;
    this->peso = peso;
}

// Retorna o vértice de origem
Vertice* Aresta::getPrimeiroVertice() {
    return primeiroVertice;
}

// Retorna o vértice de destino
Vertice* Aresta::getSegundoVertice() {
    return segundoVertice;
}

// Retorna o peso da aresta
double Aresta::getPeso() {
    return peso;
}
