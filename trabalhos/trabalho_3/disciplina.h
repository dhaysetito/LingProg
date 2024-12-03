#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

struct Disciplina {
    std::string nome;
    std::string periodo;
    int creditos;
    double nota;

    friend std::istream& operator>>(std::istream& in, Disciplina& d);
    friend std::ostream& operator<<(std::ostream& out, const Disciplina& d);

    bool operator<(const Disciplina& other) const;
    bool operator==(const Disciplina& other) const;
};

#endif
