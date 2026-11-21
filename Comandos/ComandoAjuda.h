#pragma once

#include "Comandos/Comando.h"

class ComandoAjuda : public Comando {
    public:
        ComandoAjuda();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
