#pragma once

#include "Itens/Item.h"

class ProdutoRefinado;

class MateriaPrima : public Item {
    public:
        MateriaPrima(const std::string& nome, char simbolo, int valor);

        bool eMateriaPrima() const override;
        Item* duplicar() const override;

        ProdutoRefinado* transformar() const;
};
