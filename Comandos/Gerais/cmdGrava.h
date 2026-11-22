#pragma once

#include "Comandos/Comando.h"

class cmdGrava : public Comando {
    public:
        cmdGrava();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};