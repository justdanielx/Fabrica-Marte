#pragma once

#include "Comandos/Comando.h"

class cmdAvanca : public Comando {
    public:
        cmdAvanca();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};