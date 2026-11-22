#pragma once

#include "Comandos/Comando.h"

class cmdDespede : public Comando {
    public:
        cmdDespede();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};