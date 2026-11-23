#include <stdexcept>

#include "Comandos/Tempo/cmdAvanca.h"
#include "Interface/Simulador.h"

cmdAvanca::cmdAvanca() : Comando("avanca", "avanca [n]",
    "Avanca n instantes, um de cada vez (n inteiro positivo; 1 se nao for indicado).\n"
    "Em cada instante as maquinas atuam e o ecra e apresentado no fim.\n"
    "Falha se a fabrica ainda nao existir ou se n nao for um inteiro positivo.",
    "avanca 10") {}

bool cmdAvanca::executa(Simulador& simulador, std::istringstream& parametros) const {
    int instantes = 1;

    if (!lerInteiroOpcional(parametros, instantes) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    if (instantes <= 0) throw std::invalid_argument("O numero de instantes tem de ser positivo!");

    for (int i = 0; i < instantes; i++) {
        simulador.obterFabrica().avancarInstante();
        simulador.mostrar();
    }

    return false;
}