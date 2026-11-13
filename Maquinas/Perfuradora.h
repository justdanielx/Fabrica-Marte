#pragma once

#include "Maquinas/Maquina.h"

class Perfuradora : public Maquina {
    public:
        Perfuradora(char direcao);

        void atuar() override;
        bool aceitarItem(Item* item) override;
        bool melhorar() override;
        char obterSimbolo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        int probPerda;
        int instantesDesdeExtracao;
        Item* itemPorEntregar;
};
