#include "vertice.h"

// Construtor da classe Vertice
Vertice::Vertice(string rotulo) {
    this->rotulo = rotulo;
}

// Retorna o rótulo do vértice
string Vertice::getRotulo() {
    return rotulo;
}
