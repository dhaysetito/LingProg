#ifndef ATLETA_H
#define ATLETA_H

#include <vector>
#include <string>

using namespace std;

class Atleta {
    private:
        string nome;
        vector<double> tempos;

    public:
        Atleta(string nome, vector<double> tempos);
        
        string getNome();
        vector<double> getTempos();
        
        double calcularMediaMovel(int N);
        double calcularMediaMovelAnterior(int N);
        double calcularMelhorTempo();
        double preverProximoTempo();
    };

#endif