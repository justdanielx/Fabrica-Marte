#include <stdexcept>

#include "Comandos/Engenheiros/cmdAtribui.h"
#include "Interface/Simulador.h"

cmdAtribui::cmdAtribui() : Comando("atribui", "atribui <id> <lc>",
    "Atribui o engenheiro com o numero id (inteiro positivo) a maquina da posicao lc.\n"
    "Se ja estava atribuido a outra maquina, passa para a nova.\n"
    "Falha se o engenheiro nao existir ou se a posicao nao tiver maquina.",
    "atribui 2 hr") {}

bool cmdAtribui::executa(Simulador& simulador, std::istringstream& parametros) const {
    int id = 0, linha = 0, coluna = 0;

    if (!lerInteiro(parametros, id) || !lerPosicao(parametros, linha, coluna) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    if (id <= 0) throw std::invalid_argument("O numero do engenheiro tem de ser positivo!");
    simulador.obterFabrica().obterPosicao(linha, coluna);

    throw std::logic_error("Comando valido, mas so fica disponivel na entrega final!");
}