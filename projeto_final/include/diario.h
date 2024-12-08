#ifndef DIARIO_H
#define DIARIO_H

#include <vector>
#include <string>
#include <chrono>
#include <utility>
#include "pagina.h"

/**
 * Classe Diario que representa um diário com páginas contendo conteúdo e data.
 * O diário armazena várias páginas e oferece métodos para adicionar, excluir, buscar e imprimir essas páginas.
 */
class Diario {
    public:
        // Construtor que inicializa o nome do dono e a data de criação do diário.
        Diario(const std::string& nomeDono, 
               const std::chrono::system_clock::time_point& dataCriacao);

        // Destrutor
        ~Diario();

        // Retorna o nome do dono do diário
        std::chrono::system_clock::time_point getDataCriacao() const;

        // Define o nome do dono do diário
        void setDataCriacao(const std::string& dataCricao);

        // Retorna o nome do dono do diário
        std::string getNome() const;

        // Define o nome do dono do diário
        void setNome(const std::string& nomeDono);

        // Imprime todas as páginas do diário
        void imprimirTudo() const;

        // Imprime a página específica de acordo com seu número 
        void imprimirPagina(const int numeroPagina) const;

        // Imprime a página específica de acordo com a data fornecida
        void imprimirPaginaPorData(const std::chrono::system_clock::time_point& data) const;

        // Adiciona uma nova página com uma data e conteúdo específicos
        void adicionarPagina(const std::chrono::system_clock::time_point& data, const std::string& conteudo);

        // Exclui uma página com base na data fornecida
        void excluirPagina(const std::chrono::system_clock::time_point& data);

        // Exporta o diário para um arquivo PDF
        void exportarDiarioPDF() const; 

        // Busca uma página específica pelo número
        const Pagina* buscarPagina(const int numeroPagina) const;

        // Busca uma página específica pela data
        const Pagina* buscarPaginaPorData(const std::chrono::system_clock::time_point& data) const;

        // Salva diário num txt
        void salvarDiario() const;

        // Carrega diário de um txt
        void carregarDiario();

        // Inicia diário conforme nome do dono
        void iniciarDiario(const std::string& nomeDono);

        // Conta quantas paginas rem o diário
        size_t contarPaginas() const;

        // Retorna a emoção predominante de uma página específica (informada pela data) e seu nível de intensidade
        std::pair<std::string, float> analisarPaginaEmocao (const std::chrono::system_clock::time_point& data);

        // Salva em formato de gráfico o histórico de emoções
        //void historicoEmocoes ();

        // Busca e imprime entrada por uma emocao especifica
        // void imprimePaginasEmocao (const std::string& emocao);

        // Exporta diário em PDF
        // void exportarPDF();

        std::chrono::system_clock::time_point stringParaData(const std::string& data_str);
        
        

    private:
        std::vector<Pagina> paginas;  // Armazena as páginas do diário
        std::string nomeDono;         // Nome do dono do diário
        std::chrono::system_clock::time_point dataCriacao;  // Data de criação do diário
        int numeroPagina;
        std::string emocao;

};

#endif // DIARIO_H
