/**********************************************************
 * Arquivo: aresta.h
 * Descrição: Cabeçalho da classe Aresta
 * Autora: Dhayse de Lima Tito
 **********************************************************/

#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

class Aresta {
    private:
        Vertice* verticeOrigem;  
        Vertice* verticeDestino;   
        double peso;               

    public:
        Aresta(Vertice* primeiro, Vertice* segundo, double peso); 
        Vertice* getVerticeOrigem();  
        Vertice* getVerticeDestino();   
        double getPeso();               
};

#endif
