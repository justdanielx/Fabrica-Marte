#include <iostream>
#include <stdexcept>

#include "Comandos/Listagem/cmdLposicao.h"
#include "Interface/Simulador.h"
#include "Maquinas/Maquina.h"
#include "Settings.h"

cmdLposicao::cmdLposicao() : Comando("lposicao", "lposicao <lc> [n]",
    "Mostra a informacao da posicao lc (linha e coluna em letras):\n"
    "o terreno, a quantidade de materia-prima se for um deposito\n"
    "e toda a informacao da maquina que la estiver.\n"
    "Com n (inteiro >= 0), mostra todas as posicoes do quadrado de raio n\n"
    "centrado em lc. Falha se a posicao estiver fora da fabrica.",
    "lposicao df 2") {}

bool cmdLposicao::executa(Simulador& simulador, std::istringstream& parametros) const {
    int linha = 0, coluna = 0, raio = 0;

    if (!lerPosicao(parametros, linha, coluna) || !lerInteiroOpcional(parametros, raio) || !semMaisParametros(parametros))
        throw std::invalid_argument(erroSintaxe());

    if (raio < 0) throw std::invalid_argument("O raio tem de ser maior ou igual a 0!");
    if (raio > Settings::fabrica_max_linhas + Settings::fabrica_max_colunas) raio = Settings::fabrica_max_linhas + Settings::fabrica_max_colunas;

    const Fabrica& fabrica = simulador.obterFabrica();
    fabrica.obterPosicao(linha, coluna);

    for (int i = linha - raio; i <= linha + raio; i++) {
        for (int j = coluna - raio; j <= coluna + raio; j++) {
            if (i < 0 || i >= fabrica.obterLinhas() || j < 0 || j >= fabrica.obterColunas()) continue;

            const Posicao& posicao = fabrica.obterPosicao(i, j);
            std::cout << Fabrica::nomePosicao(i, j) << ": " << posicao.obterDescricao();
            if (posicao.temMaquina()) std::cout << " | " << posicao.obterMaquina()->obterDescricao();
            std::cout << std::endl;
        }
    }

    return false;
}