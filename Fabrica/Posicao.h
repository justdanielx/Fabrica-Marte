#pragma once

#include <string>

class Posicao {
    public:
        Posicao(char tipo = ' ', int qtd = 0);

        char obterSimbolo() const;
        int obterQuantidade() const;
        bool eCratera() const;
        bool eDeposito() const;
        std::string obterDescricao() const;

    private:
        char tipoTerreno;
        int qtdMateriaPrima;
        
        inline static const int qtdTiposTerreno = 5;
        inline static const char tiposTerreno[qtdTiposTerreno] = {' ', '#', '%', '$', '~'};
};