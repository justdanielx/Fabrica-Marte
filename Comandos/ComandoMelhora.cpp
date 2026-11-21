#include <stdexcept>

#include "Comandos/ComandoMelhora.h"
#include "Interface/Simulador.h"

ComandoMelhora::ComandoMelhora() : Comando("melhora", "melhora <lc>",
    "Melhora a maquina que se encontra na posicao lc, de acordo com a sua natureza\n"
    "e pagando o respetivo custo. Se a maquina nao for melhoravel, nada acontece.\n"
    "Falha se a posicao estiver fora da fabrica, nao tiver maquina\n"
    "ou se nao houver creditos suficientes.",
    "melhora hi") {}

bool ComandoMelhora::executa(Simulador& simulador, std::istringstream& parametros) const {
    int linha = 0, coluna = 0;

    if (!lerPosicao(parametros, linha, coluna) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    simulador.obterFabrica().obterPosicao(linha, coluna);

    throw std::logic_error("Comando valido, mas so fica disponivel na entrega final!");
}
