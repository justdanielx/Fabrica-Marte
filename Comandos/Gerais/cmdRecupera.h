#pragma once

#include "Comandos/Comando.h"

class cmdRecupera : public Comando {
    public:
        cmdRecupera();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};