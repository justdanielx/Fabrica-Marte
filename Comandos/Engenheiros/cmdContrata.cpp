#include <stdexcept>

#include "Comandos/Engenheiros/cmdContrata.h"
#include "Interface/Simulador.h"

cmdContrata::cmdContrata() : Comando("contrata", "contrata <nome>",
    "Contrata um novo engenheiro com o nome indicado, que fica livre.\n"
    "O identificador e atribuido automaticamente. O nome pode repetir-se.\n"
    "Falha se nao houver creditos suficientes.",
    "contrata joaquim") {}

bool cmdContrata::executa(Simulador&, std::istringstream& parametros) const {
    std::string nome;

    if (!lerPalavra(parametros, nome) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    throw std::logic_error("Comando valido, mas so fica disponivel na entrega final!");
}