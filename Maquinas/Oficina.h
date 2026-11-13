#pragma once

#include "Maquinas/Maquina.h"

class Oficina : public Maquina {
    public:
        Oficina(char direcao);

        void atuar() override;
        bool aceitarItem(Item* item) override;
        bool melhorar() override;
        char obterSimbolo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        int placasFerro;
        int silicioPuro;
        int agua;
        int instantesRestantes;
        int melhorias;
        Item* kitPorEntregar;
};
