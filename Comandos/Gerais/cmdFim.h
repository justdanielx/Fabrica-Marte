#pragma once

#include "Comandos/Comando.h"

class cmdFim : public Comando {
    public:
        cmdFim();

        bool precisaDeFabrica() const override;
        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};