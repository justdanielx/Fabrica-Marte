#pragma once

#include "Maquinas/Maquina.h"

class Oficina : public Maquina {
    public:
        Oficina(char direcao);
        Oficina(const Oficina& outra);
        Oficina& operator=(const Oficina& outra) = delete;
        ~Oficina() override;

        void atuar(Fabrica& fabrica, int linha, int coluna) override;
        bool aceitarItem(Item* novo) override;
        char obterSimbolo() const override;
        std::string obterTipo() const override;
        std::string obterResumo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        int placasFerro;
        int silicioPuro;
        int agua;
        int instantesRestantes;
        Item* kitPorEntregar;
};