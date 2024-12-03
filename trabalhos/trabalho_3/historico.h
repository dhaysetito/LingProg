#ifndef HISTORICO_H
#define HISTORICO_H

#include "disciplina.h"
#include <vector>
#include <string>
#include <fstream>
#include <map>

/*Exibe e armazena o coeficiente de rendimento*/
class CRA {
    private:
        std::map<std::string, double> craPorPeriodo; // CRA por período
        double craGlobal;                           // CRA global

    public:
        CRA(); 

        void exibirCRA() const;

        // Permite que a classe Historico use os atributos privados
        friend class Historico;
};

class Historico {
    private:
        std::vector<Disciplina> disciplinas;
        size_t maxSize;
        std::string arquivoPersistencia;

        void carregarDisciplinas();
        void salvarDisciplinas() const;

    public:
        Historico(const std::string& arquivo, size_t maxSize = 100);
        ~Historico();

        friend std::ostream& operator<<(std::ostream& out, const Historico& h); // Imprime disciplinas

        int operator+=(const Disciplina& d); // Adiciona disciplinas
        int operator-=(const Disciplina& d); // Remove disciplinas

        std::vector<Disciplina> operator()(const std::string& periodo) const; // Busca disciplinas
        double& operator[](const std::string& nome); // Edição de nota
        void operator>>(CRA& cra) const; // Calculo do CRA

        Disciplina* buscarDisciplina(const std::string& nome);

};

#endif
