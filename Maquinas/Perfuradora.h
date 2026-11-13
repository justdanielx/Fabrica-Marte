#pragma once

#include "Maquinas/Maquina.h"

class Perfuradora : public Maquina {
    public:
        Perfuradora(char direcao);
        Perfuradora(const Perfuradora& outra);
        ~Perfuradora() override;

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
        int probPerda;
        int instantesDesdeExtracao;
        Item* itemPorEntregar;
};
