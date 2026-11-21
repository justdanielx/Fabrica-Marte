#pragma once

#include "Comandos/Comando.h"

class ComandoLposicao : public Comando {
    public:
        ComandoLposicao();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
