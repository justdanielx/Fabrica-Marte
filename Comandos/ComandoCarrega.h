#pragma once

#include "Comandos/Comando.h"

class ComandoCarrega : public Comando {
    public:
        ComandoCarrega();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
