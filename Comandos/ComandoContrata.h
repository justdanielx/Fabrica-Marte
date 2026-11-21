#pragma once

#include "Comandos/Comando.h"

class ComandoContrata : public Comando {
    public:
        ComandoContrata();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
