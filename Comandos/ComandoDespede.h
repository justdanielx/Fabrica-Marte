#pragma once

#include "Comandos/Comando.h"

class ComandoDespede : public Comando {
    public:
        ComandoDespede();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
