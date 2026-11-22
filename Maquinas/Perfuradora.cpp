#include "Maquinas/Perfuradora.h"
#include "Fabrica/Fabrica.h"
#include "Itens/MateriaPrima.h"
#include "Settings.h"

Perfuradora::Perfuradora(char direcao) : Maquina(Settings::perfuradora_custo, direcao), itemPorEntregar(nullptr) {}

Perfuradora::Perfuradora(const Perfuradora& outra) : Maquina(outra), itemPorEntregar(nullptr) {
    if (outra.itemPorEntregar != nullptr) itemPorEntregar = outra.itemPorEntregar->duplicar();
}

Perfuradora::~Perfuradora() {delete itemPorEntregar;}

void Perfuradora::atuar(Fabrica& fabrica, int linha, int coluna) {
    if (itemPorEntregar != nullptr) {
        if (itemPorEntregar->obterInstanteChegada() < fabrica.obterInstante() &&
            fabrica.entregar(linha, coluna, obterDirecao(), itemPorEntregar))
                itemPorEntregar = nullptr;
        return;
    }

    char deposito = fabrica.extrairMateriaPrima(linha, coluna);
    if (deposito == ' ') return;

    itemPorEntregar = MateriaPrima::doDeposito(deposito);
    itemPorEntregar->marcarChegada(fabrica.obterInstante());
    fabrica.registar("perfuradora em " + Fabrica::nomePosicao(linha, coluna) + " extraiu " + itemPorEntregar->obterSimbolo());
}

bool Perfuradora::aceitarItem(Item*) {return false;}

char Perfuradora::obterSimbolo() const {return 'P';}

std::string Perfuradora::obterTipo() const {return "Perfuradora";}

std::string Perfuradora::obterResumo() const {
    if (itemPorEntregar == nullptr) return "sem itens";
    return "por entregar: " + itemPorEntregar->obterNome();
}

std::string Perfuradora::obterDescricao() const {return descricaoBase() + " | " + obterResumo();}

Maquina* Perfuradora::duplicar() const {return new Perfuradora(*this);}