#include <stdexcept>

#include "Comandos/ComandoFabrica.h"
#include "Interface/Simulador.h"

ComandoFabrica::ComandoFabrica() : Comando("fabrica", "fabrica <nl> <nc>",
    "Cria a fabrica com nl linhas e nc colunas (inteiros entre 1 e 26).\n"
    "As crateras e os depositos sao colocados em posicoes aleatorias.\n"
    "Falha se a fabrica ja existir, se as dimensoes forem invalidas\n"
    "ou se a fabrica for pequena demais para as crateras e depositos.",
    "fabrica 12 20") {}

bool ComandoFabrica::precisaDeFabrica() const {return false;}

bool ComandoFabrica::executa(Simulador& simulador, std::istringstream& parametros) const {
    int linhas = 0, colunas = 0;

    if (!lerInteiro(parametros, linhas) || !lerInteiro(parametros, colunas) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    if (simulador.temFabrica()) throw std::logic_error("A fabrica ja foi criada!");

    simulador.criarFabrica(new Fabrica(linhas, colunas));
    return true;
}
