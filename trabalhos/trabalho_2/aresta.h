#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

class Aresta {
    private:
        Vertice* primeiroVertice;  // Vertice de origem
        Vertice* segundoVertice;   // Vertice de destino
        double peso;               // Peso da aresta

    public:
        Aresta(Vertice* primeiro, Vertice* segundo, double peso); 
        Vertice* getPrimeiroVertice();  
        Vertice* getSegundoVertice();   
        double getPeso();               
};

#endif
