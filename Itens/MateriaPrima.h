#pragma once

#include "Itens/Item.h"
#include "Itens/ProdutoRefinado.h"

class MateriaPrima : public Item {
    public:
        MateriaPrima(const std::string& nome, char simbolo, int valor);

        static MateriaPrima* doDeposito(char deposito);

        bool eMateriaPrima() const override;
        ProdutoRefinado* transformar() const override;
        Item* duplicar() const override;
};
