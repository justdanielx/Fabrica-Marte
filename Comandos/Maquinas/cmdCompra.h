#pragma once

#include "Comandos/Comando.h"

class cmdCompra : public Comando {
    public:
        cmdCompra();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};