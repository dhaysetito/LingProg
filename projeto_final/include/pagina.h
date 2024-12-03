#ifndef PAGINA_H
#define PAGINA_H

#include <chrono>
#include <string>

class Pagina {
    public:
        // Construtor
        Pagina(std::chrono::system_clock::time_point data, const std::string& conteudo);

        // Métodos de acesso
        std::string getConteudo() const; // Retorna o conteúdo da página
        std::chrono::system_clock::time_point getData() const; // Retorna a data da página

        // Métodos de modificação
        void setConteudo(const std::string& conteudo); // Altera o conteúdo da página
        void setData(const std::chrono::system_clock::time_point& data); // Altera a data da página

    private:
        std::chrono::system_clock::time_point data; // Data da página
        std::string conteudo; // Conteúdo da página
};

#endif // PAGINA_H
