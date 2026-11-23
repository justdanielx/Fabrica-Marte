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

ProdutoRefinado* MateriaPrima::transformar() const {return nullptr;}

Item* MateriaPrima::duplicar() const {return new MateriaPrima(*this);}