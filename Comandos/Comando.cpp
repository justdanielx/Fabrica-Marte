#include "Comandos/Comando.h"

Comando::Comando(const std::string& nome, const std::string& sintaxe, const std::string& descricao, const std::string& exemplo)
    : nome(nome), sintaxe(sintaxe), descricao(descricao), exemplo(exemplo) {}

Comando::~Comando() {}

std::string Comando::obterNome() const {return nome;}
std::string Comando::obterSintaxe() const {return sintaxe;}

std::string Comando::obterAjuda() const {
    std::ostringstream oss;

    oss << "Sintaxe: " << sintaxe << std::endl
        << descricao << std::endl
        << "Exemplo: " << exemplo;
    return oss.str();
}

bool Comando::precisaDeFabrica() const {return true;}

std::string Comando::erroSintaxe() const {return "Sintaxe invalida! Use: " + sintaxe;}

bool Comando::lerPalavra(std::istringstream& parametros, std::string& palavra) {
    return static_cast<bool>(parametros >> palavra);
}

bool Comando::converterInteiro(const std::string& texto, int& valor) {
    std::istringstream iss(texto);
    char resto;

    if (!(iss >> valor)) return false;
    if (iss >> resto) return false;
    return true;
}

bool Comando::lerInteiro(std::istringstream& parametros, int& valor) {
    std::string texto;

    if (!lerPalavra(parametros, texto)) return false;
    return converterInteiro(texto, valor);
}

bool Comando::lerInteiroOpcional(std::istringstream& parametros, int& valor) {
    std::string texto;

    if (!lerPalavra(parametros, texto)) return true;
    return converterInteiro(texto, valor);
}

bool Comando::lerPosicao(std::istringstream& parametros, int& linha, int& coluna) {
    std::string texto;

    if (!lerPalavra(parametros, texto)) return false;
    if (texto.size() != 2) return false;
    if (texto[0] < 'a' || texto[0] > 'z' || texto[1] < 'a' || texto[1] > 'z') return false;

    linha = texto[0] - 'a';
    coluna = texto[1] - 'a';
    return true;
}

bool Comando::lerDirecao(std::istringstream& parametros, char& direcao) {
    std::string texto;

    if (!lerPalavra(parametros, texto)) return false;
    if (texto != "c" && texto != "b" && texto != "e" && texto != "d") return false;

    direcao = texto[0];
    return true;
}

bool Comando::semMaisParametros(std::istringstream& parametros) {
    std::string resto;

    return !(parametros >> resto);
}
