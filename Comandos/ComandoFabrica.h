#pragma once

#include "Comandos/Comando.h"

class ComandoFabrica : public Comando {
    public:
        ComandoFabrica();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
