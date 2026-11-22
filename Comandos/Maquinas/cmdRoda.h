#pragma once

#include "Comandos/Comando.h"

class cmdRoda : public Comando {
    public:
        cmdRoda();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};