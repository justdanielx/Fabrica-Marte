#pragma once

#include "Maquinas/Maquina.h"

class Transportador : public Maquina {
    public:
        Transportador(char direcao);
        Transportador(const Transportador& outra);
        ~Transportador() override;

        void atuar(Fabrica& fabrica, int linha, int coluna) override;
        bool aceitarItem(Item* item) override;
        char obterSimbolo() const override;
        std::string obterTipo() const override;
        std::string obterResumo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        Item* item;
};
