#pragma once

#include "Maquinas/Maquina.h"

class Silo : public Maquina {
    public:
        Silo(char direcao);
        ~Silo() override;
        Silo(const Silo& outro);
        Silo& operator=(const Silo& outro);

        void atuar() override;
        bool aceitarItem(Item* item) override;
        bool melhorar() override;
        char obterSimbolo() const override;
        std::string obterDescricao() const override;
        Maquina* duplicar() const override;

    private:
        Item** itens;
        int quantidade;
        int probPerda;
};
