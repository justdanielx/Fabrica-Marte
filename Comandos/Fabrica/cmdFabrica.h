#pragma once

#include "Comandos/Comando.h"

class cmdFabrica : public Comando {
    public:
        cmdFabrica();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};