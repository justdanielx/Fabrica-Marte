#pragma once

#include "Maquinas/Maquina.h"

class Refinaria : public Maquina {
    public:
        Refinaria(char direcao);

        void atuar() override;
        bool aceitarItem(Item* item) override;
        char obterSimbolo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        Item* item;
        int instantesRestantes;
};
