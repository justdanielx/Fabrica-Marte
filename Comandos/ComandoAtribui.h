#pragma once

#include "Comandos/Comando.h"

class ComandoAtribui : public Comando {
    public:
        ComandoAtribui();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
