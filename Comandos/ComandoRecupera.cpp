#include <stdexcept>

#include "Comandos/ComandoRecupera.h"
#include "Interface/Simulador.h"

ComandoRecupera::ComandoRecupera() : Comando("recupera", "recupera <nome>",
    "Recupera a copia da fabrica com o nome indicado. A fabrica volta a ser\n"
    "como era quando a copia foi feita; os engenheiros ficam livres.\n"
    "A copia nao e eliminada. Falha se nao existir copia com esse nome.",
    "recupera antes") {}

bool ComandoRecupera::executa(Simulador& simulador, std::istringstream& parametros) const {
    std::string nome;

    if (!lerPalavra(parametros, nome) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    simulador.obterFabrica();

    throw std::logic_error("Comando valido, mas so fica disponivel na entrega final!");
}
