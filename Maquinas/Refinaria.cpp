#include "Maquinas/Refinaria.h"
#include "Itens/Item.h"
#include "Settings.h"

Refinaria::Refinaria(char direcao) : Maquina(Settings::refinaria_custo, direcao), item(nullptr), instantesRestantes(0) {}

Refinaria::Refinaria(const Refinaria& outra) : Maquina(outra), item(nullptr), instantesRestantes(outra.instantesRestantes) {
    if (outra.item != nullptr) item = outra.item->duplicar();
}

Refinaria::~Refinaria() {delete item;}

void Refinaria::atuar(Fabrica&, int, int) {}

bool Refinaria::aceitarItem(Item* novo) {
    if (item != nullptr || !novo->eMateriaPrima()) return false;

    item = novo;
    instantesRestantes = duracaoComEngenheiros(Settings::refinaria_duracao);
    return true;
}

char Refinaria::obterSimbolo() const {return 'R';}

std::string Refinaria::obterTipo() const {return "Refinaria";}

std::string Refinaria::obterResumo() const {
    if (item == nullptr) return "vazia";
    return "tem " + item->obterNome();
}

std::string Refinaria::obterDescricao() const {return descricaoBase() + " | " + obterResumo();}

Maquina* Refinaria::duplicar() const {return new Refinaria(*this);}