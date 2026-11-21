#pragma once

#include "Comandos/Comando.h"

class ComandoRecupera : public Comando {
    public:
        ComandoRecupera();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
