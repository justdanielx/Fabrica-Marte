#pragma once

#include "Comandos/Comando.h"

class ComandoGrava : public Comando {
    public:
        ComandoGrava();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
