#pragma once

#include "Comandos/Comando.h"

class ComandoAvanca : public Comando {
    public:
        ComandoAvanca();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
