#include "diario.h"

// Contrutor
Diario::Diario(const std::string& nomeDono, 
               const std::chrono::system_clock::time_point& dataCriacao)
    : nomeDono(nomeDono), dataCriacao(dataCriacao) {}

// Destrutor
Diario::~Diario() {}

