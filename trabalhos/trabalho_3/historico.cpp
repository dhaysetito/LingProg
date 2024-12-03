#include "historico.h"
#include <algorithm>
#include <iostream>

Historico::Historico(const std::string& arquivo, size_t maxSize)
    : maxSize(maxSize), arquivoPersistencia(arquivo) {
    carregarDisciplinas();
}

Historico::~Historico() {
    salvarDisciplinas();
}

void Historico::carregarDisciplinas() {
    std::ifstream arquivo(arquivoPersistencia);
    if (!arquivo.is_open()) 
        return;

    Disciplina d;
    while (arquivo >> d.nome >> d.periodo >> d.creditos >> d.nota) {
        disciplinas.push_back(d);
    }

    arquivo.close();
}

void Historico::salvarDisciplinas() const {
    std::ofstream arquivo(arquivoPersistencia);
    for (const auto& d : disciplinas) {
        arquivo << d.nome << " " << d.periodo << " " << d.creditos << " " << d.nota << std::endl;
    }
    arquivo.close();
}

std::ostream& operator<<(std::ostream& out, const Historico& h) {
    for (const auto& d : h.disciplinas)
        out << d << std::endl;
    return out;
}

int Historico::operator+=(const Disciplina& d) {
    if (disciplinas.size() >= maxSize || std::find(disciplinas.begin(), disciplinas.end(), d) != disciplinas.end())
        return -1;

    disciplinas.push_back(d);
    std::sort(disciplinas.begin(), disciplinas.end());
    return std::distance(disciplinas.begin(), std::find(disciplinas.begin(), disciplinas.end(), d));
}

int Historico::operator-=(const Disciplina& d) {
    auto it = std::find_if(disciplinas.begin(), disciplinas.end(), [&](const Disciplina& x) { return x.nome == d.nome; });
    if (it != disciplinas.end()) {
        int index = std::distance(disciplinas.begin(), it);
        disciplinas.erase(it);
        return index;
    }
    return -1;
}

std::vector<Disciplina> Historico::operator()(const std::string& periodo) const {
    std::vector<Disciplina> resultado;
    for (const auto& d : disciplinas) {
        if (d.periodo == periodo)
            resultado.push_back(d);
    }
    return resultado;
}

double& Historico::operator[](const std::string& nome) {
    for (auto& d : disciplinas) {
        if (d.nome == nome)
            return d.nota;
    }
    throw std::invalid_argument("Disciplina não encontrada");
}

// Construtor o CRA
CRA::CRA() : craGlobal(0.0) {}

// Função para exibir os CRAs por período e global
void CRA::exibirCRA() const {
    std::cout << "CRA por período:\n";
    for (const auto& pair : craPorPeriodo) {
        std::cout << "Período " << pair.first << ": " << pair.second << '\n';
    }
    std::cout << "CRA Global: " << craGlobal << '\n';
}

// Implementação do operador >> para cálculo do CRA
void Historico::operator>>(CRA& cra) const {
    std::map<std::string, double> somaNotasPorPeriodo;
    std::map<std::string, int> somaCreditosPorPeriodo;
    double somaGlobalNotas = 0.0;
    int somaGlobalCreditos = 0;

    for (const auto& disciplina : disciplinas) {
        // Acumulando para o CRA por período
        somaNotasPorPeriodo[disciplina.periodo] += disciplina.nota * disciplina.creditos;
        somaCreditosPorPeriodo[disciplina.periodo] += disciplina.creditos;

        // Acumulando para o CRA global
        somaGlobalNotas += disciplina.nota * disciplina.creditos;
        somaGlobalCreditos += disciplina.creditos;
    }

    // Calculando o CRA por período
    for (const auto& pair : somaNotasPorPeriodo) {
        const std::string& periodo = pair.first;
        double somaNotas = pair.second;

        int creditos = somaCreditosPorPeriodo[periodo];
        if (creditos > 0) {
            cra.craPorPeriodo[periodo] = somaNotas / creditos;
        }
    }


    // Calculando o CRA global
    if (somaGlobalCreditos > 0) {
        cra.craGlobal = somaGlobalNotas / somaGlobalCreditos;
    }
}

Disciplina* Historico::buscarDisciplina(const std::string& nome) {
    for (auto& d : disciplinas) {
        if (d.nome == nome)
            return &d;
    }
    return nullptr;
}
