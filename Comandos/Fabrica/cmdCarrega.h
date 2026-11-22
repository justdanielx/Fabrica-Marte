#pragma once

#include "Comandos/Comando.h"

class cmdCarrega : public Comando {
    public:
        cmdCarrega();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};