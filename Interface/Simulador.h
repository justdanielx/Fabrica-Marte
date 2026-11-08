#pragma once

#include <string>

#include "Interface/Ecra.h"
#include "Fabrica/Fabrica.h"

class Simulador {
    public:
        Simulador(int linhas, int colunas);
        Simulador(const std::string& nomeFicheiro);

        std::string obterSimulador() const;
        std::string descreverPosicao(const std::string& posicao) const;
        void executar();

    private:
        Fabrica fabrica;
};  