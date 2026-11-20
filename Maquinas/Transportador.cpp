#include "Maquinas/Transportador.h"
#include "Fabrica/Fabrica.h"
#include "Itens/Item.h"
#include "Settings.h"

Transportador::Transportador(char direcao) : Maquina(Settings::transportador_custo, direcao), item(nullptr) {}

Transportador::Transportador(const Transportador& outra) : Maquina(outra), item(nullptr) {
    if (outra.item != nullptr) item = outra.item->duplicar();
}

Transportador::~Transportador() {delete item;}

void Transportador::atuar(Fabrica& fabrica, int linha, int coluna) {
    if (item == nullptr) return;
    if (item->obterInstanteChegada() >= fabrica.obterInstante()) return;

    if (fabrica.entregar(linha, coluna, obterDirecao(), item)) item = nullptr;
}

bool Transportador::aceitarItem(Item* novo) {
    if (item != nullptr) return false;

    item = novo;
    return true;
}

char Transportador::obterSimbolo() const {
    if (item != nullptr) return item->obterSimbolo();

    if (obterDirecao() == 'c') return '^';
    if (obterDirecao() == 'b') return 'v';
    if (obterDirecao() == 'e') return '<';
    return '>';
}

std::string Transportador::obterTipo() const {return "Transportador";}

std::string Transportador::obterResumo() const {
    if (item == nullptr) return "vazio";
    return "leva " + item->obterNome();
}

std::string Transportador::obterDescricao() const {return descricaoBase() + " | " + obterResumo();}

Maquina* Transportador::duplicar() const {return new Transportador(*this);}
