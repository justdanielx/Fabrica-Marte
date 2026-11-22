#pragma once

#include "Comandos/Comando.h"

class cmdContrata : public Comando {
    public:
        cmdContrata();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};