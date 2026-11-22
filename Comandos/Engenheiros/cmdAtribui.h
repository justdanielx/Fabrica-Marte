#pragma once

#include "Comandos/Comando.h"

class cmdAtribui : public Comando {
    public:
        cmdAtribui();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};