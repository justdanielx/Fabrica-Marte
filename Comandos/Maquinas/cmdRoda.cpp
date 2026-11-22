#include <iostream>
#include <stdexcept>

#include "Comandos/Maquinas/cmdRoda.h"
#include "Interface/Simulador.h"

cmdRoda::cmdRoda() : Comando("roda", "roda <lc> <dir>",
    "Muda a direcao de saida da maquina que se encontra na posicao lc.\n"
    "dir: c (cima), b (baixo), e (esquerda), d (direita).\n"
    "Falha se a posicao estiver fora da fabrica ou nao tiver maquina.",
    "roda ce b") {}

bool cmdRoda::executa(Simulador& simulador, std::istringstream& parametros) const {
    int linha = 0, coluna = 0;
    char direcao = ' ';

    if (!lerPosicao(parametros, linha, coluna) || !lerDirecao(parametros, direcao) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    simulador.obterFabrica().rodar(linha, coluna, direcao);
    std::cout << "Maquina rodada para " << direcao << "!" << std::endl;
    return true;
}