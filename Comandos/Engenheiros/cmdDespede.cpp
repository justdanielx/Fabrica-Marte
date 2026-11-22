#include <stdexcept>

#include "Comandos/Engenheiros/cmdDespede.h"
#include "Interface/Simulador.h"

cmdDespede::cmdDespede() : Comando("despede", "despede <id>",
    "Envia o engenheiro com o numero id (inteiro positivo) de volta para a Terra.\n"
    "Deixa de fazer parte da fabrica e de receber salario.\n"
    "Falha se o engenheiro nao existir.",
    "despede 2") {}

bool cmdDespede::executa(Simulador&, std::istringstream& parametros) const {
    int id = 0;

    if (!lerInteiro(parametros, id) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    if (id <= 0) throw std::invalid_argument("O numero do engenheiro tem de ser positivo!");

    throw std::logic_error("Comando valido, mas so fica disponivel na entrega final!");
}