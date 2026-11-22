#include <sstream>

#include "Maquinas/Lancador.h"
#include "Itens/Item.h"
#include "Settings.h"

Lancador::Lancador(char direcao) : Maquina(Settings::lancador_custo, direcao), item(nullptr), instantesRecarga(0), probPerda(Settings::lancador_prob_perda) {}

Lancador::Lancador(const Lancador& outra) : Maquina(outra), item(nullptr), instantesRecarga(outra.instantesRecarga), probPerda(outra.probPerda) {
    if (outra.item != nullptr) item = outra.item->duplicar();
}

Lancador::~Lancador() {delete item;}

void Lancador::atuar(Fabrica&, int, int) {}

bool Lancador::aceitarItem(Item* novo) {
    if (item != nullptr) return false;

    item = novo;
    return true;
}

char Lancador::obterSimbolo() const {return 'L';}

std::string Lancador::obterTipo() const {return "Lancador";}

std::string Lancador::obterResumo() const {
    if (item == nullptr) return "vazio";
    return "por lancar: " + item->obterNome();
}

std::string Lancador::obterDescricao() const {
    std::ostringstream oss;

    oss << descricaoBase() << " | perda " << probPerda << "% | " << obterResumo();
    return oss.str();
}

Maquina* Lancador::duplicar() const {return new Lancador(*this);}