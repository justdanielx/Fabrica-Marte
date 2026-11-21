#pragma once

#include "Comandos/Comando.h"

class ComandoEstado : public Comando {
    public:
        ComandoEstado();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
