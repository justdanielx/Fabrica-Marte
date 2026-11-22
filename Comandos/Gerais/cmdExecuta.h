#pragma once

#include "Comandos/Comando.h"

class cmdExecuta : public Comando {
    public:
        cmdExecuta();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};