#include <stdexcept>

#include "Comandos/Gerais/cmdExecuta.h"
#include "Interface/Simulador.h"

cmdExecuta::cmdExecuta() : Comando("executa", "executa <nome-do-ficheiro>",
    "Le e executa os comandos do ficheiro indicado, um por linha,\n"
    "exatamente com o mesmo formato dos comandos escritos no teclado.\n"
    "Falha se o ficheiro nao existir.",
    "executa teste1.txt") {}

bool cmdExecuta::precisaDeFabrica() const {return false;}

bool cmdExecuta::executa(Simulador& simulador, std::istringstream& parametros) const {
    std::string nomeFicheiro;

    if (!lerPalavra(parametros, nomeFicheiro) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    simulador.executarFicheiro(nomeFicheiro);
    return false;
}