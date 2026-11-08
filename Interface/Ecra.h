#pragma once

#include <string>

#include "Settings.h"
class Ecra {
    public:
        Ecra(int linhas, int colunas);

        void limpar();
        bool posicionar(int linha, int coluna);

        bool escrever(const std::string& texto);
        bool escrever(const std::string& texto, int linha, int coluna);
        bool escrever(const char caracter);
        bool escrever(const char caracter, int linha, int coluna);

        bool moldura(int linha, int coluna, int altura, int largura); 
        std::string obterBuffer() const;

    private:
        int linhasUsadas;
        int colunasUsadas;
        char buffer[Settings::ecra_max_linhas][Settings::ecra_max_colunas];

        int linhaCursor;
        int colunaCursor;
};