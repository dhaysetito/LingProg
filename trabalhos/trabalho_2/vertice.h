/**********************************************************
 * Arquivo: vertice.h
 * Descrição: Cabeçalho da classe Vertice
 * Autora: Dhayse de Lima Tito
 **********************************************************/

#ifndef VERTICE_H
#define VERTICE_H

#include <string>
using namespace std;

class Vertice {
    private:
        string rotulo; 

    public:
        Vertice(string rotulo); 
        string getRotulo(); 
};

#endif