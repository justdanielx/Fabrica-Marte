#include <iostream>
#include <stdexcept>

#include "Comandos/ComandoCompra.h"
#include "Interface/Simulador.h"

ComandoCompra::ComandoCompra() : Comando("compra", "compra <tipo> <lc> <dir>",
    "Compra uma maquina e coloca-a na posicao lc com a direcao de saida dir.\n"
    "tipo: p (perfuradora), t (transportador), r (refinaria), o (oficina),\n"
    "s (silo) ou l (lancador). dir: c (cima), b (baixo), e (esquerda), d (direita).\n"
    "Falha se a posicao estiver fora da fabrica, ocupada, for uma cratera\n"
    "ou se nao houver creditos suficientes.",
    "compra t ce d") {}

bool ComandoCompra::executa(Simulador& simulador, std::istringstream& parametros) const {
    std::string tipo;
    int linha = 0, coluna = 0;
    char direcao = ' ';

    if (!lerPalavra(parametros, tipo) || !lerPosicao(parametros, linha, coluna) ||
        !lerDirecao(parametros, direcao) || !semMaisParametros(parametros))
            throw std::invalid_argument(erroSintaxe());

    if (tipo.size() != 1 || std::string("ptrosl").find(tipo[0]) == std::string::npos)
        throw std::invalid_argument("Tipo de maquina invalido! Use p, t, r, o, s ou l!");

    simulador.obterFabrica().comprar(tipo[0], linha, coluna, direcao);
    std::cout << "Maquina comprada em " << Fabrica::nomePosicao(linha, coluna) << "!" << std::endl;
    return true;
}
