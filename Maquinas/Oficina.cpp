#include <sstream>

#include "Maquinas/Oficina.h"
#include "Itens/Item.h"
#include "Settings.h"

Oficina::Oficina(char direcao) : Maquina(Settings::oficina_custo, direcao), placasFerro(0), silicioPuro(0), agua(0), instantesRestantes(0), kitPorEntregar(nullptr) {}

Oficina::Oficina(const Oficina& outra) : Maquina(outra), placasFerro(outra.placasFerro), silicioPuro(outra.silicioPuro), agua(outra.agua), instantesRestantes(outra.instantesRestantes), kitPorEntregar(nullptr) {
    if (outra.kitPorEntregar != nullptr) kitPorEntregar = outra.kitPorEntregar->duplicar();
}

Oficina::~Oficina() {delete kitPorEntregar;}

void Oficina::atuar(Fabrica&, int, int) {}

bool Oficina::aceitarItem(Item* novo) {
    if (kitPorEntregar != nullptr) return false;

    char simbolo = novo->obterSimbolo();

    if (simbolo == 'p' && placasFerro < Settings::oficina_receita_placas_ferro) placasFerro++;
    else if (simbolo == 'i' && silicioPuro < Settings::oficina_receita_silicio_puro) silicioPuro++;
    else if (simbolo == 'a' && agua < Settings::oficina_receita_agua) agua++;
    else return false;

    delete novo;
    return true;
}

char Oficina::obterSimbolo() const {return 'O';}

std::string Oficina::obterTipo() const {return "Oficina";}

std::string Oficina::obterResumo() const {
    std::ostringstream oss;

    if (kitPorEntregar != nullptr) return "kit por entregar";

    oss << "placas " << placasFerro << "/" << Settings::oficina_receita_placas_ferro
        << ", silicio " << silicioPuro << "/" << Settings::oficina_receita_silicio_puro
        << ", agua " << agua << "/" << Settings::oficina_receita_agua;
    return oss.str();
}

std::string Oficina::obterDescricao() const {return descricaoBase() + " | " + obterResumo();}

Maquina* Oficina::duplicar() const {return new Oficina(*this);}
