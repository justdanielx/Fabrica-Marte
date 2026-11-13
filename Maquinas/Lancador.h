#pragma once

#include "Maquinas/Maquina.h"

class Lancador : public Maquina {
    public:
        Lancador(char direcao);
        Lancador(const Lancador& outra);
        ~Lancador() override;

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
        Item* item;
        int instantesRecarga;
        int probPerda;
};
