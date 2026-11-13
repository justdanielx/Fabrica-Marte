#pragma once

#include "Itens/Item.h"

class ProdutoRefinado : public Item {
    public:
        ProdutoRefinado(const std::string& nome, char simbolo, int valor);

        bool eMateriaPrima() const override;
        Item* duplicar() const override;
};
