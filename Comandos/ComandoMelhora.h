#pragma once

#include "Comandos/Comando.h"

class ComandoMelhora : public Comando {
    public:
        ComandoMelhora();

        bool executa(Simulador& simulador, std::istringstream& parametros) const override;
};
