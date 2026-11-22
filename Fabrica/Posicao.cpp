#include <string>
#include <stdexcept>
#include <sstream>

#include "Posicao.h"
#include "Maquinas/Maquina.h"

bool Posicao::eCratera() const {
    if (tipoTerreno == '#') return true;
    return false;
}

bool Posicao::eDeposito() const {
    if (tipoTerreno == '%' || tipoTerreno == '$' || tipoTerreno == '~') return true;
    return false;
}

Posicao::Posicao(char tipo, int qtd) : tipoTerreno(tipo), qtdMateriaPrima(qtd), maquina(nullptr) {
    bool encontrado = false;

    for (int i = 0; i < qtdTiposTerreno; i++) 
        if (tipoTerreno == tiposTerreno[i])
            encontrado = true;

    if (!encontrado)
        throw std::invalid_argument("Tipo Inexistente!");

    if (!eDeposito())
        qtdMateriaPrima = 0;
}

Posicao::Posicao(const Posicao& outra) : tipoTerreno(outra.tipoTerreno), qtdMateriaPrima(outra.qtdMateriaPrima), maquina(nullptr) {
    if (outra.maquina != nullptr) maquina = outra.maquina->duplicar();
}

Posicao& Posicao::operator=(const Posicao& outra) {
    if (this == &outra) return *this;

    Maquina* copia = nullptr;
    if (outra.maquina != nullptr) copia = outra.maquina->duplicar();

    delete maquina;
    maquina = copia;
    tipoTerreno = outra.tipoTerreno;
    qtdMateriaPrima = outra.qtdMateriaPrima;

    return *this;
}

Posicao::~Posicao() {delete maquina;}

char Posicao::obterSimbolo() const {return tipoTerreno;}
int Posicao::obterQuantidade() const {return qtdMateriaPrima;}

char Posicao::obterSimboloEcra() const {
    if (maquina != nullptr) return maquina->obterSimbolo();
    return tipoTerreno;
}

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

bool Posicao::temMaquina() const {return maquina != nullptr;}
Maquina* Posicao::obterMaquina() {return maquina;}
const Maquina* Posicao::obterMaquina() const {return maquina;}

void Posicao::colocarMaquina(Maquina* nova) {
    if (eCratera()) throw std::invalid_argument("Nao e possivel colocar maquinas em crateras!");
    if (maquina != nullptr) throw std::invalid_argument("A posicao ja esta ocupada!");

    maquina = nova;
}

void Posicao::removerMaquina() {
    delete maquina;
    maquina = nullptr;
}

char Posicao::extrair() {
    if (!eDeposito() || qtdMateriaPrima <= 0) return ' ';

    char deposito = tipoTerreno;
    qtdMateriaPrima--;
    if (qtdMateriaPrima == 0) tipoTerreno = ' ';

    return deposito;
}