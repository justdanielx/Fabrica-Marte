#pragma once

#include "Comandos/Comando.h"

class ComandoExecuta : public Comando {
    public:
        ComandoExecuta();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
