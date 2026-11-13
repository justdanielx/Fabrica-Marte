#pragma once

#include <string>

class Item;

class Maquina {
    public:
        Maquina(int custo, char direcao);
        virtual ~Maquina();

        virtual void atuar() = 0;
        virtual bool aceitarItem(Item* item) = 0;
        virtual bool melhorar();
        virtual char obterSimbolo() const = 0;
        virtual std::string obterDescricao() const = 0;
        virtual Maquina* duplicar() const = 0;

        int obterCusto() const;
        char obterDirecao() const;
        bool rodar(char novaDirecao);

    private:
        int custo;
        char direcao;
};
