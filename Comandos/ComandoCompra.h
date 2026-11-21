#pragma once

#include "Comandos/Comando.h"

class ComandoCompra : public Comando {
    public:
        ComandoCompra();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
