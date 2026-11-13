#pragma once

#include "Maquinas/Maquina.h"

class Silo : public Maquina {
    public:
        Silo(char direcao);
        Silo(const Silo& outra);
        ~Silo() override;

        void atuar(Fabrica& fabrica, int linha, int coluna) override;
        bool aceitarItem(Item* item) override;
        bool melhorar() override;
        int obterCustoMelhoria() const override;
        char obterSimbolo() const override;
        std::string obterTipo() const override;
        std::string obterResumo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        Item** itens;
        int quantidade;
        int probPerda;
};
