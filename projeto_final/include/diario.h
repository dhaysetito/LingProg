#ifndef DIARIO_H
#define DIARIO_H

#include <vector>

#include "pagina.h"

using namespace std;

/*Classe Diario que possui paginas com conteudo e data.*/
class Diario{
    public:
        // Construtor
        Diario(const std::string& nomeDono, 
           const std::chrono::system_clock::time_point& dataCriacao);

        // Destrutor
        ~Diario();

        void imprimirTudo() const;
        void imprimirPagina(std::chrono::system_clock::time_point& data) const;
        void adicionarPagina(const std::chrono::system_clock::time_point& data, const std::string& conteudo);
        void excluirPagina(std::chrono::system_clock::time_point& data);
        void exportarDiarioPDF() const; // Exporta diário em PDF
        const Pagina* buscarPaginaPorData(const std::chrono::system_clock::time_point& data) const;

    private:
        vector<Pagina> paginas;
        std::string nomeDono;
        std::chrono::system_clock::time_point dataCriacao;
};


#endif