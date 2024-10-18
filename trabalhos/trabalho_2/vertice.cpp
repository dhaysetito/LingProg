/**********************************************************
 * Arquivo: vertice.cpp
 * Descrição: Implementação da classe Vertice -
 *            Representa o nome do rotulo 
 * Autora: Dhayse de Lima Tito
 **********************************************************/

#include "vertice.h"

// Construtor da classe Vertice
Vertice::Vertice(string rotulo) {
    this->rotulo = rotulo;
}

// Retorna o rótulo do vértice
string Vertice::getRotulo() {
    return rotulo;
}
