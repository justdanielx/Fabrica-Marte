#pragma once

#include <string>
#include <vector>
#include <map>

#include "Settings.h"
#include "Posicao.h"

class Item;

class Fabrica {
    public:
        Fabrica(int linhas, int colunas);
        Fabrica(const std::string& nomeFicheiro);

        int obterLinhas() const;
        int obterColunas() const;
        int obterCreditos() const;
        int obterInstante() const;
        int obterNumeroMaquinas() const;
        const Posicao& obterPosicao(int linha, int coluna) const;
        const std::vector<std::string>& obterResumo() const;
        const std::map<std::string, int>& obterEnviados() const;

        void avancarInstante();
        bool entregar(int linha, int coluna, char direcao, Item* item);
        char extrairMateriaPrima(int linha, int coluna);
        void registar(const std::string& evento);

        static bool sortearProbabilidade(int percentagem);
        static std::string nomePosicao(int linha, int coluna);

    private:
        int linhasUsadas;
        int colunasUsadas;
        Posicao grelha[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];

        int creditos;
        int instante;
        std::vector<std::string> resumo;
        std::map<std::string, int> enviados;

        static int sortear(int min, int max);
        void colocar(char tipo, int qtd);
        bool dentro(int linha, int coluna) const;
        Posicao& posicaoEm(int linha, int coluna);
};
