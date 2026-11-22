#include "Itens/ProdutoRefinado.h"

ProdutoRefinado::ProdutoRefinado(const std::string& nome, char simbolo, int valor) : Item(nome, simbolo, valor) {}

bool ProdutoRefinado::eMateriaPrima() const {return false;}

Item* ProdutoRefinado::duplicar() const {return new ProdutoRefinado(*this);}