#pragma once

#include "Comandos/Comando.h"

class cmdAjuda : public Comando {
    public:
        cmdAjuda();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};