#pragma once

#include "Maquinas/Maquina.h"

class Refinaria : public Maquina {
    public:
        Refinaria(char direcao);
        Refinaria(const Refinaria& outra);
        ~Refinaria() override;

        void atuar(Fabrica& fabrica, int linha, int coluna) override;
        bool aceitarItem(Item* item) override;
        char obterSimbolo() const override;
        std::string obterTipo() const override;
        std::string obterResumo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        Item* item;
        int instantesRestantes;
};
