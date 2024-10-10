#include <iostream>
#include <algorithm>
#include <iomanip>

#include "treinador.h"

using namespace std;

Treinador::Treinador() {}

void Treinador::adicionarAtleta(Atleta atleta) {
    atletas.push_back(atleta);
}

/* Exibe a média de tempos de cada atleta até o tempo N que ele possui 
 * N mínimo = 3 e máximo = 7
 */
void Treinador::exibirEvolucaoMedia() {
    for (auto& atleta : atletas) {
        cout << "Atleta: " << atleta.getNome() << "\n";
        
        // Obtém o número de tempos que o atleta possui
        int numeroDeTempos = atleta.getTempos().size();
        
        for (int N = 3; N <= numeroDeTempos; ++N) {
            cout << fixed << setprecision(2);
            cout << "Média móvel (N=" << N << "): " << atleta.calcularMediaMovel(N) << "\n";
            if (N == 7) break;
        }
        cout << "\n";
    }
}

/* Exibe se o atleta teve - nos ultimos N treinos - melhora, pioria ou manteve estabilidade.
 * Possui limar de 10% (se abaixo melhora, se acima piora, outro estabilidade)
 */
void Treinador::exibirMelhoriaDesempenho() {
    double limiar = 0.10;  // Limiar 10%
    int N;
    

    cout << "Digite quantos treinos devem ser considerados para cálculo da média (3 a 7): ";
    cin >> N;
    cout << "\n";

    if (N < 3 || N > 7) {
        cout << "Valor inválido! Usando o valor padrão de N = 3.\n\n";
        N = 3; 
    }

    for (auto& atleta : atletas) {
        cout << "Atleta: " << atleta.getNome() << " - ";

        int numeroDeTempos = atleta.getTempos().size();

        double mediaAtual = atleta.calcularMediaMovel(N);
        double mediaAnterior = atleta.calcularMediaMovelAnterior(N-1);

        if (mediaAtual < 0 || mediaAnterior < 0 ||  N >= numeroDeTempos) {
            cout << "Dados insuficientes para calcular médias.\n";
            continue;
        }

        // Diferença percentual
        double diferenca = (mediaAnterior - mediaAtual) / mediaAnterior;

        // Imprime desempenho
        if (diferenca >= limiar) {
            cout << fixed << setprecision(1); // Seta precisão para uma casa decimal
            cout << "Melhoria de desempenho (" << diferenca * 100 << "% de redução no tempo).\n";
        } else if (diferenca <= -limiar) {
            cout << fixed << setprecision(1);
            cout << "Piora de desempenho (" << -diferenca * 100 << "% de aumento no tempo).\n";
        } else {
            cout << "Desempenho estável.\n";
        }
    }
}

/* Ordena os atletas pela média de todos tempo de cada atleta. 
 */
void Treinador::ordenarAtletasPorMedia() {
    sort(atletas.begin(), atletas.end(), [](Atleta& a, Atleta& b) {
        int N = a.getTempos().size(); // Obtém o número de tempos do atleta

        // Calcula a média móvel usando N
        double mediaA = a.calcularMediaMovel(N); 
        double mediaB = b.calcularMediaMovel(N);
        return mediaA < mediaB;
    });

    for (auto& atleta : atletas) {
        int N = atleta.getTempos().size(); // Obtém o número de tempos do 
        cout << fixed << setprecision(2);
        cout << atleta.getNome() << " - Média: " << atleta.calcularMediaMovel(N) << "\n";
    }
}

/* Ordena os atletas pelo melhor tempo obtido dentre todos.
 */
void Treinador::ordenarAtletasPorMelhorTempo() {
    sort(atletas.begin(), atletas.end(), [](Atleta& a, Atleta& b) {
        return a.calcularMelhorTempo() < b.calcularMelhorTempo();
    });

    for (auto& atleta : atletas) {
        cout << atleta.getNome() << " - Melhor Tempo: " << atleta.calcularMelhorTempo() << "\n";
    }
}
/* Informa a precisão do próximo tempo de cada jogador por meio de regressão linear.
 */
void Treinador::preverProximoTempo() {
    for (auto& atleta : atletas) {
        cout << "Atleta: " << atleta.getNome() << " - Previsão próximo tempo: " << atleta.preverProximoTempo() << "\n";
    }
}