#pragma once

#include "Comandos/Comando.h"

class cmdVende : public Comando {
    public:
        cmdVende();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};