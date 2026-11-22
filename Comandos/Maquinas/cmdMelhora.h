#pragma once

#include "Comandos/Comando.h"

class cmdMelhora : public Comando {
    public:
        cmdMelhora();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};