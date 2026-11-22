#include <sstream>

#include "Maquinas/Perfuradora.h"
#include "Fabrica/Fabrica.h"
#include "Itens/MateriaPrima.h"
#include "Settings.h"

Perfuradora::Perfuradora(char direcao) : Maquina(Settings::perfuradora_custo, direcao), probPerda(Settings::perfuradora_prob_perda), instantesDesdeExtracao(0), itemPorEntregar(nullptr) {}

Perfuradora::Perfuradora(const Perfuradora& outra) : Maquina(outra), probPerda(outra.probPerda), instantesDesdeExtracao(outra.instantesDesdeExtracao), itemPorEntregar(nullptr) {
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

    instantesDesdeExtracao++;
    if (instantesDesdeExtracao < duracaoComEngenheiros(Settings::perfuradora_periodo)) return;
    instantesDesdeExtracao = 0;

    char deposito = fabrica.extrairMateriaPrima(linha, coluna);
    if (deposito == ' ') return;

    MateriaPrima* extraida = MateriaPrima::doDeposito(deposito);

    if (Fabrica::sortearProbabilidade(probPerda)) {
        fabrica.registar("perfuradora em " + Fabrica::nomePosicao(linha, coluna) + " perdeu " + extraida->obterSimbolo());
        delete extraida;
        return;
    }

    extraida->marcarChegada(fabrica.obterInstante());
    itemPorEntregar = extraida;
    fabrica.registar("perfuradora em " + Fabrica::nomePosicao(linha, coluna) + " extraiu " + extraida->obterSimbolo());
}

bool Perfuradora::aceitarItem(Item*) {return false;}

char Perfuradora::obterSimbolo() const {return 'P';}

std::string Perfuradora::obterTipo() const {return "Perfuradora";}

std::string Perfuradora::obterResumo() const {
    if (itemPorEntregar == nullptr) return "sem itens";
    return "por entregar: " + itemPorEntregar->obterNome();
}

std::string Perfuradora::obterDescricao() const {
    std::ostringstream oss;

    oss << descricaoBase() << " | perda " << probPerda << "% | extrai a cada "
        << duracaoComEngenheiros(Settings::perfuradora_periodo) << " instantes (passaram "
        << instantesDesdeExtracao << ") | " << obterResumo();
    return oss.str();
}

Maquina* Perfuradora::duplicar() const {return new Perfuradora(*this);}