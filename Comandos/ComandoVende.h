#pragma once

#include "Comandos/Comando.h"

class ComandoVende : public Comando {
    public:
        ComandoVende();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
