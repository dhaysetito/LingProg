#include "pagina.h"
#include <chrono>
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <iomanip>
#include <sstream>


// Construtor
Pagina::Pagina(int numeroPagina, std::chrono::system_clock::time_point data, const std::string& conteudo)
    : numeroPagina(numeroPagina), data(data), conteudo(conteudo) {}

// Métodos de acesso
int Pagina::getNumeroPagina() const {
    return numeroPagina;
}

std::string Pagina::getConteudo() const {
    return conteudo;
}

std::chrono::system_clock::time_point Pagina::getData() const {
    return data;
}

// Métodos de modificação
void Pagina::setNumeroPagina(const int numeroPagina) {
    this->numeroPagina = numeroPagina;
}

void Pagina::setConteudo(const std::string& conteudo) {
    this->conteudo = conteudo;
}

void Pagina::setData(const std::string& data_str) {
    std::tm tm = {};
    std::stringstream ss(data_str);
    ss >> std::get_time(&tm, "%d/%m/%Y"); // Formato esperado: "dd/mm/yyyy"
    if (ss.fail()) {
        std::cerr << "Erro ao converter a data!" << std::endl;
        throw std::invalid_argument("Formato de data inválido");
    }
    // Converte a string para time_point e atribui a data
    this->data = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

// Método para imprimir a data e conteúdo da página
void Pagina::imprimir() const {
    // Converte o time_point para time_t
    std::time_t data_t = std::chrono::system_clock::to_time_t(getData());
    
    // Converte time_t para uma estrutura tm
    std::tm tm = *std::localtime(&data_t);

    // Imprime a página, a data formatada e o conteúdo
    std::cout << "Página " << numeroPagina << " - " 
              << "Data: " << std::put_time(&tm, "%d/%m/%Y") << std::endl; // Formato dd/mm/yyyy
    std::cout << "Conteúdo: " << conteudo << std::endl;
}