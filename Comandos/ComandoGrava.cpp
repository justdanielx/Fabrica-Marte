#include <stdexcept>

#include "Comandos/ComandoGrava.h"
#include "Interface/Simulador.h"

ComandoGrava::ComandoGrava() : Comando("grava", "grava <nome>",
    "Guarda em memoria uma copia da fabrica e de tudo o que nela se encontra,\n"
    "associada ao nome indicado. Se ja existir uma copia com esse nome,\n"
    "e substituida. As associacoes dos engenheiros nao ficam na copia.",
    "grava antes") {}

bool ComandoGrava::executa(Simulador&, std::istringstream& parametros) const {
    std::string nome;

    if (!lerPalavra(parametros, nome) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    throw std::logic_error("Comando valido, mas so fica disponivel na entrega final!");
}
