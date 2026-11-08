#pragma once

#include "Settings.h"
#include "Posicao.h"

class Fabrica {
    public:
        Fabrica(int linhas, int colunas);

        int obterLinhas() const;
        int obterColunas() const;
        int obterCreditos() const;
        int obterInstante() const;
        const Posicao& obterPosicao(int linha, int coluna) const;

    private:
        int linhasUsadas;
        int colunasUsadas;
        Posicao grelha[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];

        int creditos;
        int instante;

        static int sortear(int min, int max);
        void colocar(char tipo, int qtd);
};