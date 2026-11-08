#include <string>
#include <stdexcept>
#include <sstream>

#include "Posicao.h"

bool Posicao::eCratera() const {
    if (tipoTerreno == '#') return true;
    return false;
}

bool Posicao::eDeposito() const {
    if (tipoTerreno == '%' || tipoTerreno == '$' || tipoTerreno == '~') return true;
    return false;
}

Posicao::Posicao(char tipo, int qtd) : tipoTerreno(tipo), qtdMateriaPrima(qtd) {
    bool encontrado = false;

    for (int i = 0; i < qtdTiposTerreno; i++) 
        if (tipoTerreno == tiposTerreno[i])
            encontrado = true;

    if (!encontrado)
        throw std::invalid_argument("Tipo Inexistente!");

    if (!eDeposito())
        qtdMateriaPrima = 0;
}

char Posicao::obterSimbolo() const {return tipoTerreno;}
int Posicao::obterQuantidade() const {return qtdMateriaPrima;}

std::string Posicao::obterDescricao() const {
    std::ostringstream oss;

    if (tipoTerreno == ' ') oss << "Solo";
    else if (tipoTerreno == '#') oss << "Cratera";
    else if (tipoTerreno == '%') oss << "Deposito de ferro";
    else if (tipoTerreno == '$') oss << "Deposito de silicio";
    else if (tipoTerreno == '~') oss << "Deposito de gelo";

    if (eDeposito()) oss << " com " << qtdMateriaPrima << " unidades";

    return oss.str();
}