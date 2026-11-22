#pragma once

#include "Comandos/Comando.h"

class cmdEstado : public Comando {
    public:
        cmdEstado();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};