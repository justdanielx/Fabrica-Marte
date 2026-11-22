#pragma once

#include <string>

class Maquina;

class Posicao {
    public:
        Posicao(char tipo = ' ', int qtd = 0);
        Posicao(const Posicao& outra);
        Posicao& operator=(const Posicao& outra);
        ~Posicao();

        char obterSimbolo() const;
        char obterSimboloEcra() const;
        int obterQuantidade() const;
        bool eCratera() const;
        bool eDeposito() const;
        std::string obterDescricao() const;

        bool temMaquina() const;
        Maquina* obterMaquina();
        const Maquina* obterMaquina() const;
        void colocarMaquina(Maquina* nova);
        void removerMaquina();

        char extrair();

    private:
        char tipoTerreno;
        int qtdMateriaPrima;
        Maquina* maquina;

        inline static const int qtdTiposTerreno = 5;
        inline static const char tiposTerreno[qtdTiposTerreno] = {' ', '#', '%', '$', '~'};
};