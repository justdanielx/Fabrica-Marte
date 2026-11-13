#pragma once

#include "Maquinas/Maquina.h"

class Lancador : public Maquina {
    public:
        Lancador(char direcao);

        void atuar() override;
        bool aceitarItem(Item* item) override;
        bool melhorar() override;
        char obterSimbolo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        Item* item;
        int instantesRecarga;
        int probPerda;
};
