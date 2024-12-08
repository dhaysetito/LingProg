#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <pybind11/embed.h>

#include "diario.h"

namespace py = pybind11;

// Contrutor
Diario::Diario(const std::string& nomeDono, 
               const std::chrono::system_clock::time_point& dataCriacao)
    : nomeDono(nomeDono), dataCriacao(dataCriacao) {}

// Destrutor
Diario::~Diario() {}

std::string Diario::getNome() const{
    return nomeDono;
}

void Diario::setNome(const std::string& nomeDono){
    this->nomeDono = nomeDono;
}

std::chrono::system_clock::time_point Diario::getDataCriacao() const{
    return dataCriacao;
}

void Diario::setDataCriacao(const std::string& data_criacao){
    std::tm tm = {};
    std::stringstream ss(data_criacao);
    ss >> std::get_time(&tm, "%d/%m/%Y"); // Formato esperado: "dd/mm/yyyy"
    if (ss.fail()) {
        std::cerr << "Erro ao converter a data!" << std::endl;
        throw std::invalid_argument("Formato de data inválido");
    }
    // Converte a string para time_point e atribui a data
    this->dataCriacao = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

void Diario::imprimirTudo() const {
    // Converte a dataCriacao (time_point) para time_t
    std::time_t data_t = std::chrono::system_clock::to_time_t(dataCriacao);

    // Converte time_t para tm (estrutura para exibição de data)
    std::tm tm = *std::localtime(&data_t);

    std::cout << "\n\n-----------------------------------------" << std::endl;
    std::cout << "Diário de " << nomeDono << " - " 
              << std::put_time(&tm, "%d/%m/%Y") << std::endl;
    std::cout << "-----------------------------------------\n" << std::endl;
    for (const auto& pagina : paginas) {
        pagina.imprimir();
        std::cout << "--------------------------------------------------------------------" << std::endl;
    }
}

void Diario::imprimirPagina(const int numeroPagina) const{
    const Pagina* pagina = buscarPagina(numeroPagina);

    if (pagina) {
        pagina->imprimir();
    } else{
        std::cout << "Página não encontrada, digite um valor entre 1 e " << contarPaginas() << "." << std::endl;
    }
}

void Diario::imprimirPaginaPorData(const std::chrono::system_clock::time_point& data) const{
    const Pagina* pagina = buscarPaginaPorData(data);
    if (pagina) {
        pagina->imprimir();
    } else {
        std::cout << "Página com a data fornecida não encontrada!" << std::endl;
    }
}

void Diario::adicionarPagina(const std::chrono::system_clock::time_point& data, const std::string& conteudo) {
    int numeroPagina = paginas.size() + 1;  // Incrementa o número da página
    Pagina novaPagina(numeroPagina, data, conteudo);
    paginas.push_back(novaPagina);
}

void Diario::excluirPagina(const std::chrono::system_clock::time_point &data){
    auto it = std::find_if(paginas.begin(), paginas.end(), 
                           [&data](const Pagina& pagina) { return pagina.getData() == data; });
    
    if (it != paginas.end()) {
        paginas.erase(it);
        std::cout << "Página excluída com sucesso." << std::endl;
    } else {
        std::cout << "Página não encontrada para a data fornecida." << std::endl;
    }
}

void Diario::exportarDiarioPDF() const{
    std::cout << "Exportando diário para PDF..." << std::endl;
}

const Pagina *Diario::buscarPagina(const int numeroPagina) const{
    for (const auto& pagina : paginas) {
        if (pagina.getNumeroPagina() == numeroPagina) {
            return &pagina;
        }
    }
    return nullptr; // Retorna nullptr se a página não for encontrada
}

const Pagina *Diario::buscarPaginaPorData(const std::chrono::system_clock::time_point &data) const{
    for (const auto& pagina : paginas) {
        if (pagina.getData() == data) {
            return &pagina;
        }
    }
    return nullptr; // Retorna nullptr se a página não for encontrada
}

// Função para salvar o diário em um arquivo de texto
void Diario::salvarDiario() const {
    // Abrindo o arquivo em modo de escrita
    std::string nomeArq= "data/output/diario" + nomeDono + ".txt";
    std::ofstream arquivo(nomeArq);

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para salvar o diário." << std::endl;
        return;
    }

    // Converte a dataCriacao (time_point) para time_t
    std::time_t data_t = std::chrono::system_clock::to_time_t(dataCriacao);

    // Converte time_t para tm (estrutura para exibição de data)
    std::tm tm = *std::localtime(&data_t);

    // Escreve o nome do dono do diário
    arquivo << "Diário de " << nomeDono << "\nCriado em: " << std::put_time(&tm, "%d/%m/%Y") << "\n\n";

    // Itera pelas páginas do diário
    for (const auto& pagina : paginas) {
        // Converte o time_point para time_t
        std::time_t data_t = std::chrono::system_clock::to_time_t(pagina.getData());
        // Converte time_t para tm
        std::tm tm = *std::localtime(&data_t);

        // Escreve o número da página, data e conteúdo no arquivo
        arquivo << "Página " << pagina.getNumeroPagina() << "\n"
                << "Data: " << std::put_time(&tm, "%d/%m/%Y") << "\n"
                << "Conteúdo: " << pagina.getConteudo() << "\n\n";
    }

    // Fecha o arquivo após salvar os dados
    arquivo.close();

    // Confirmação
    std::cout << "Diário salvo com sucesso em '" << nomeArq << "' ." << std::endl;
}

void Diario::carregarDiario() {
    // Definindo o caminho do arquivo
    std::string nomeArq = "data/output/diario" + nomeDono + ".txt";

    // Tentando abrir o arquivo em modo de leitura
    std::ifstream arquivo(nomeArq);

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para carregar o diário." << std::endl;
        return;
    }

    std::string linha;
    bool lendoPagina = false;
    int numeroPagina;
    std::string conteudo;
    std::string dataStr;
    std::string dataCriacaoStr;
    std::chrono::system_clock::time_point data;

    // Lê a primeira linha do arquivo, que contém o nome do dono
    if (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string ignoreWord;  // Palavra "Diário de"
        ss >> ignoreWord >> ignoreWord >> nomeDono;  // Captura tudo após "Diário de"
        setNome(nomeDono);
    }

    // Lê a segunda linha do arquivo, que contém a data de criação
    if (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string ignoreCriadoEm;  // Palavra "Criado em:"
        ss >> ignoreCriadoEm >> ignoreCriadoEm >> dataCriacaoStr;  // Captura a data após "Criado em:"
        setDataCriacao(dataCriacaoStr);
    }

    // Agora vamos ler as páginas do diário
    while (std::getline(arquivo, linha)) {
        if (linha.find("Página") != std::string::npos) {
            // Processa a linha que contém "Página"
            std::stringstream ss(linha);
            ss >> linha >> numeroPagina;  // Ex: "Página 1"
            lendoPagina = true;
            conteudo.clear();  // Limpa o conteúdo
        } 
        if (lendoPagina && linha.find("Data:") != std::string::npos) {
            // Processa a linha que contém "Data:"
            std::stringstream ss(linha);
            std::string ignoreData;
            ss >> ignoreData >> dataStr;  // Ex: "Data: 12/10/2024"
            data = stringParaData(dataStr);  // Função que converte a string para std::chrono::time_point
        }
        if (lendoPagina && linha.find("Conteúdo: ") != std::string::npos) {
            // Encontrar a posição onde "Conteúdo:" termina
            size_t pos = linha.find("Conteúdo: ") + std::strlen("Conteúdo: ");
            
            // Agora captura o conteúdo após "Conteúdo:"
            conteudo = linha.substr(pos);  // Pega o conteúdo após a string "Conteúdo:"
            
            // Adiciona a página ao diário
            adicionarPagina(data, conteudo);
            lendoPagina = false;
        }
    }

    arquivo.close();
    std::cout << "Diário carregado com sucesso de '" << nomeArq << "'." << std::endl;
}



void Diario::iniciarDiario(const std::string& nomeDono) {
    // Define o caminho do arquivo do diário
    std::string nomeArq = "data/output/diario" + nomeDono + ".txt";

    // Verifica se o arquivo já existe
    std::ifstream arquivo(nomeArq);

    // Se o arquivo existir, carrega o diário
    if (arquivo.is_open()) {
        std::cout << "Diário encontrado! Carregando...\n";
        setNome(nomeDono);  // Atualiza o nome do dono
        carregarDiario();   // Carrega os dados do diário
    } else {
        // Se o arquivo não existir, cria um novo diário
        std::cout << "Nenhum diário encontrado. Criando um novo diário...\n";
        setNome(nomeDono);  // Atualiza o nome do dono
        // Se necessário, pode inicializar o diário com a data de criação, por exemplo:
        this->dataCriacao = std::chrono::system_clock::now();
    }
}

size_t Diario::contarPaginas() const{
    return paginas.size();
}

std::pair<std::string, float> Diario::analisarPaginaEmocao(const std::chrono::system_clock::time_point& data) {
    std::string emocao;
    float probabilidade = 0.0f;

    const Pagina* pagina = buscarPaginaPorData(data);

    // Verifica se a página foi encontrada
    if (!pagina) {
        std::cerr << "Erro: Página não encontrada para a data fornecida." << std::endl;
        return {"Erro", 0.0f};
    }

    try {
        // Importa o módulo onde a classe ModeloEmocoes está definida
        py::module modelo_modulo = py::module::import("modelo_emocoes");

        // Instancia a classe ModeloEmocoes
        py::object modelo = modelo_modulo.attr("ModeloEmocoes")(
            "models/modelo_de_emocoes_lr0.1_bs64_ep10/best-model.pt"
        );

        // Chama o método prever_emocao
        py::tuple resultado = modelo.attr("prever_emocao")(pagina->getConteudo()).cast<py::tuple>();

        // Extrai a emoção e a probabilidade do retorno (tuple)
        emocao = resultado[0].cast<std::string>();      // Primeiro elemento: emoção
        probabilidade = resultado[1].cast<float>();    // Segundo elemento: probabilidade
    } catch (const py::error_already_set& e) {
        std::cerr << "Erro ao executar função Python: " << e.what() << std::endl;
        return {"Erro", 0.0f};
    }

    return {emocao, probabilidade};
}

std::chrono::system_clock::time_point Diario::stringParaData(const std::string& data_str) {
    std::tm tm = {};
    std::stringstream ss(data_str);

    // Usamos std::get_time para fazer a conversão da string para std::tm
    ss >> std::get_time(&tm, "%d/%m/%Y");  // Formato esperado: "dd/mm/yyyy"
    
    if (ss.fail()) {
        std::cerr << "Erro ao converter a data! Formato esperado: dd/mm/yyyy" << std::endl;
    }

    // Converte o tm para time_t
    std::time_t time = std::mktime(&tm);

    // Retorna o time_point com base no time_t
    return std::chrono::system_clock::from_time_t(time);
}
