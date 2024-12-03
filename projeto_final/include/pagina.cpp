#include "pagina.h"

// Construtor
Pagina::Pagina(std::chrono::system_clock::time_point data, const std::string &conteudo): data(data), conteudo(conteudo){}

// Métodos de acesso
std::string Pagina::getConteudo() const {
    return conteudo;
}

std::chrono::system_clock::time_point Pagina::getData() const {
    return data;
}

// Métodos de modificação
void Pagina::setConteudo(const std::string& novoConteudo) {
    conteudo = novoConteudo;
}

void Pagina::setData(const std::chrono::system_clock::time_point& novaData) {
    data = novaData;
}
