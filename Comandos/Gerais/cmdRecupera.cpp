#include <stdexcept>

#include "Comandos/Gerais/cmdRecupera.h"
#include "Interface/Simulador.h"

cmdRecupera::cmdRecupera() : Comando("recupera", "recupera <nome>",
    "Recupera a copia da fabrica com o nome indicado. A fabrica volta a ser\n"
    "como era quando a copia foi feita; os engenheiros ficam livres.\n"
    "A copia nao e eliminada. Falha se nao existir copia com esse nome.",
    "recupera antes") {}

bool cmdRecupera::executa(Simulador&, std::istringstream& parametros) const {
    std::string nome;

    if (!lerPalavra(parametros, nome) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    throw std::logic_error("Comando valido, mas so fica disponivel na entrega final!");
}