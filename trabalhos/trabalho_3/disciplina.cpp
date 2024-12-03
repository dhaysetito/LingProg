#include "disciplina.h"

std::istream& operator>>(std::istream& in, Disciplina& d) {
    std::cout << "Digite o nome da disciplina: ";
    in >> d.nome;
    std::cout << "Digite o período de conclusão (ex: 2023.1): ";
    in >> d.periodo;
    std::cout << "Digite o número de créditos: ";
    in >> d.creditos;
    std::cout << "Digite a nota final: ";
    in >> d.nota;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Disciplina& d) {
    out << "Nome: " << d.nome
        << ", Período: " << d.periodo
        << ", Créditos: " << d.creditos
        << ", Nota: " << d.nota;
    return out;
}

bool Disciplina::operator<(const Disciplina& other) const {
    if (periodo != other.periodo)
        return periodo < other.periodo;
    return nome < other.nome;
}

bool Disciplina::operator==(const Disciplina& other) const {
    return nome == other.nome;
}
