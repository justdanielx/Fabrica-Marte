#pragma once

#include "Interface/Ecra.h"
#include "Fabrica/Fabrica.h"

class Simulador {
    public:
        Simulador(int linhas, int colunas);

        std::string obterSimulador() const;

    private:
        Fabrica fabrica;
};  