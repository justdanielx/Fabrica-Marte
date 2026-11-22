#include <stdexcept>

#include "Comandos/Fabrica/cmdCarrega.h"
#include "Interface/Simulador.h"

cmdCarrega::cmdCarrega() : Comando("carrega", "carrega <nome-do-ficheiro>",
    "Cria a fabrica a partir do mapa descrito no ficheiro indicado.\n"
    "Falha se a fabrica ja existir, se o ficheiro nao existir\n"
    "ou se nao respeitar o formato do mapa.",
    "carrega mapa1.txt") {}

bool cmdCarrega::precisaDeFabrica() const {return false;}

bool cmdCarrega::executa(Simulador& simulador, std::istringstream& parametros) const {
    std::string nomeFicheiro;

    if (!lerPalavra(parametros, nomeFicheiro) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    if (simulador.temFabrica()) throw std::logic_error("A fabrica ja foi criada!");

    simulador.criarFabrica(new Fabrica(nomeFicheiro));
    return true;
}