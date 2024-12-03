#ifndef PAGINA_H
#define PAGINA_H

#include <chrono>
#include <string>
#include <iostream>

class Pagina {
    public:
        // Construtor
        Pagina(int numeroPagina, std::chrono::system_clock::time_point data, const std::string& conteudo);

        // Métodos de acesso
        int getNumeroPagina() const;
        std::string getConteudo() const;  // Retorna o conteúdo da página
        std::chrono::system_clock::time_point getData() const;  // Retorna a data da página

        // Métodos de modificação
        void setNumeroPagina(const int numeroPagina); // Número da página
        void setConteudo(const std::string& conteudo); // Altera o conteúdo da página
        void setData(const std::string& data_str); // Altera a data da página

        // Método para imprimir a data e conteúdo da página
        void imprimir() const;

    private:
        int numeroPagina;
        std::chrono::system_clock::time_point data;  // Data da página
        std::string conteudo;  // Conteúdo da página
};

#endif // PAGINA_H
