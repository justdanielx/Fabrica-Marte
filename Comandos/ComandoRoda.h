#pragma once

#include "Comandos/Comando.h"

class ComandoRoda : public Comando {
    public:
        ComandoRoda();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
