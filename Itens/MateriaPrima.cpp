#include "Itens/MateriaPrima.h"
#include "Settings.h"

MateriaPrima::MateriaPrima(const std::string& nome, char simbolo, int valor) : Item(nome, simbolo, valor) {}

MateriaPrima* MateriaPrima::doDeposito(char deposito) {
    if (deposito == '%') return new MateriaPrima("Minerio de ferro", 'f', Settings::valor_minerio_ferro);
    if (deposito == '$') return new MateriaPrima("Silicio bruto", 's', Settings::valor_silicio_bruto);
    if (deposito == '~') return new MateriaPrima("Gelo", 'g', Settings::valor_gelo);
    return nullptr;
}

bool MateriaPrima::eMateriaPrima() const {return true;}

ProdutoRefinado* MateriaPrima::transformar() const {
    if (obterSimbolo() == 'f') return new ProdutoRefinado("Placa de ferro", 'p', Settings::valor_placa_ferro);
    if (obterSimbolo() == 's') return new ProdutoRefinado("Silicio puro", 'i', Settings::valor_silicio_puro);
    if (obterSimbolo() == 'g') return new ProdutoRefinado("Agua", 'a', Settings::valor_agua);
    return nullptr;
}

Item* MateriaPrima::duplicar() const {return new MateriaPrima(*this);}
