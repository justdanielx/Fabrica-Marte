#include <iostream>
#include <stdexcept>

#include "Comandos/ComandoVende.h"
#include "Interface/Simulador.h"

ComandoVende::ComandoVende() : Comando("vende", "vende <lc>",
    "Vende a maquina que se encontra na posicao lc, recebendo a fabrica\n"
    "uma percentagem do custo de compra. Os itens dentro da maquina perdem-se.\n"
    "Falha se a posicao estiver fora da fabrica ou nao tiver maquina.",
    "vende ce") {}

bool ComandoVende::executa(Simulador& simulador, std::istringstream& parametros) const {
    int linha = 0, coluna = 0;

    if (!lerPosicao(parametros, linha, coluna) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    int valor = simulador.obterFabrica().vender(linha, coluna);
    std::cout << "Maquina vendida por " << valor << " creditos!" << std::endl;
    return true;
}
