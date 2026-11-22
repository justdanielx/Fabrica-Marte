#pragma once

#include "Comandos/Comando.h"

class cmdLposicao : public Comando {
    public:
        cmdLposicao();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};