#pragma once

#include "Comandos/Comando.h"

class ComandoFim : public Comando {
    public:
        ComandoFim();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
