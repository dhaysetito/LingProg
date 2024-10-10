#ifndef TREINADOR_H
#define TREINADOR_H

#include <vector>
#include "atleta.h"

using namespace std;

class Treinador {
private:
    vector<Atleta> atletas;

public:
    Treinador();
    
    void adicionarAtleta(Atleta atleta);
    void exibirEvolucaoMedia();
    void exibirMelhoriaDesempenho();
    void ordenarAtletasPorMedia();
    void ordenarAtletasPorMelhorTempo();
    void preverProximoTempo();
};

#endif