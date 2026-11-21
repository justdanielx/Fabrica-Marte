#include <sstream>

#include "Maquinas/Silo.h"
#include "Fabrica/Fabrica.h"
#include "Itens/Item.h"
#include "Settings.h"

Silo::Silo(char direcao) : Maquina(Settings::silo_custo, direcao), itens(nullptr), quantidade(0), probPerda(Settings::silo_prob_perda) {}

Silo::Silo(const Silo& outro) : Maquina(outro), itens(nullptr), quantidade(0), probPerda(outro.probPerda) {
    copiar(outro);
}

Silo& Silo::operator=(const Silo& outro) {
    if (this == &outro) return *this;

    Maquina::operator=(outro);
    libertar();
    probPerda = outro.probPerda;
    copiar(outro);

    return *this;
}

Silo::~Silo() {libertar();}

void Silo::copiar(const Silo& outro) {
    if (outro.quantidade == 0) return;

    itens = new Item*[outro.quantidade];
    for (int i = 0; i < outro.quantidade; i++)
        itens[i] = outro.itens[i]->duplicar();

    quantidade = outro.quantidade;
}

void Silo::libertar() {
    for (int i = 0; i < quantidade; i++)
        delete itens[i];

    delete[] itens;
    itens = nullptr;
    quantidade = 0;
}

void Silo::acrescentar(Item* novo) {
    Item** maior = new Item*[quantidade + 1];

    for (int i = 0; i < quantidade; i++)
        maior[i] = itens[i];
    maior[quantidade] = novo;

    delete[] itens;
    itens = maior;
    quantidade++;
}

Item* Silo::retirarMaisAntigo() {
    if (quantidade == 0) return nullptr;

    Item* antigo = itens[0];
    Item** menor = nullptr;

    if (quantidade > 1) {
        menor = new Item*[quantidade - 1];
        for (int i = 1; i < quantidade; i++)
            menor[i - 1] = itens[i];
    }

    delete[] itens;
    itens = menor;
    quantidade--;

    return antigo;
}

void Silo::atuar(Fabrica& fabrica, int linha, int coluna) {
    if (quantidade == 0) return;

    if (Fabrica::sortearProbabilidade(probPerda)) {
        Item* perdido = retirarMaisAntigo();
        fabrica.registar("silo em " + Fabrica::nomePosicao(linha, coluna) + " perdeu " + perdido->obterNome());
        delete perdido;

        if (quantidade == 0) return;
    }

    if (itens[0]->obterInstanteChegada() >= fabrica.obterInstante()) return;

    if (fabrica.entregar(linha, coluna, obterDirecao(), itens[0])) retirarMaisAntigo();
}

bool Silo::aceitarItem(Item* novo) {
    acrescentar(novo);
    return true;
}

char Silo::obterSimbolo() const {return 'S';}

std::string Silo::obterTipo() const {return "Silo";}

std::string Silo::obterResumo() const {
    if (quantidade == 0) return "vazio";
    return std::to_string(quantidade) + " itens";
}

std::string Silo::obterDescricao() const {
    std::ostringstream oss;

    oss << descricaoBase() << " | perda " << probPerda << "% | " << obterResumo();
    if (quantidade > 0) {
        oss << " (do mais antigo para o mais recente:";
        for (int i = 0; i < quantidade; i++)
            oss << " " << itens[i]->obterSimbolo();
        oss << ")";
    }

    return oss.str();
}

Maquina* Silo::duplicar() const {return new Silo(*this);}
