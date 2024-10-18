#ifndef VERTICE_H
#define VERTICE_H

#include <string>
using namespace std;

class Vertice {
    private:
        string rotulo;  // Rótulo ou nome do vértice

    public:
        Vertice(string rotulo);  // Construtor
        string getRotulo();  // Retorna o rótulo do vértice
};

#endif