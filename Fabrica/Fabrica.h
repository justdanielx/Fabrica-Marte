#pragma once

#include "Settings.h"
#include "Posicao.h"

class Fabrica {
    public:
        Fabrica(int linhas, int colunas);

    private:
        int linhasUsadas;
        int colunasUsadas;
        Posicao grelha[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];

        int creditos;
        int instante;

        static int sortear(int min, int max);
        void colocar(char tipo, int qtd);
};