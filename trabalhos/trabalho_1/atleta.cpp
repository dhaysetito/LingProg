#include <numeric>
#include <iostream>
#include <algorithm>

#include "atleta.h"

using namespace std;

Atleta::Atleta(string nome, vector<double> tempos) : nome(nome), tempos(tempos) {}

string Atleta::getNome() {
    return nome;
}

vector<double> Atleta::getTempos() {
    return tempos;
}

/* Calcula a média móvel de N tempos do atleta dos últimos N tempos.
 */
double Atleta::calcularMediaMovel(int N) {
    if (tempos.size() < static_cast<size_t>(N)) return -1;
    return accumulate(tempos.end() - N, tempos.end(), 0.0) / N;
}

/* Calcula a média móvel de N tempos do atleta dos últimos N - 1 tempos.
 */
double Atleta::calcularMediaMovelAnterior(int N) {
    if (tempos.size() < static_cast<size_t>(N + 1)) return -1;
    return accumulate(tempos.end() - N - 1, tempos.end() - 1, 0.0) / N;
}

/* Calcula o menor tempo do atleta em toda temporada.
 */
double Atleta::calcularMelhorTempo() {
    return *min_element(tempos.begin(), tempos.end());
}

/* Utiliza regressão linear simples para prever o tempo do próximo treino de um atleta com base nos tempos anteriores
 */
double Atleta::preverProximoTempo() {
    int n = tempos.size();
    double xSum = 0, ySum = 0, xySum = 0, xxSum = 0;

    for (int i = 0; i < n; ++i) {
        xSum += i + 1;
        ySum += tempos[i];
        xySum += (i + 1) * tempos[i];
        xxSum += (i + 1) * (i + 1);
    }

    double b = (n * xySum - xSum * ySum) / (n * xxSum - xSum * xSum);
    double a = (ySum - b * xSum) / n;

    return a + b * (n + 1); // Previsão para o próximo treino
}