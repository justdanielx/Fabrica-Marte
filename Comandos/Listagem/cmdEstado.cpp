#include <iostream>
#include <stdexcept>

#include "Comandos/Listagem/cmdEstado.h"
#include "Interface/Simulador.h"
#include "Maquinas/Maquina.h"

cmdEstado::cmdEstado() : Comando("estado", "estado",
    "Apresenta o instante atual, os creditos, as maquinas (tipo, posicao,\n"
    "direcao, engenheiros e resumo do conteudo), os engenheiros e o total\n"
    "de itens enviados com sucesso para a Terra, de cada tipo.\n"
    "Falha se a fabrica ainda nao existir.",
    "estado") {}

bool cmdEstado::executa(Simulador& simulador, std::istringstream& parametros) const {
    if (!semMaisParametros(parametros)) throw std::invalid_argument(erroSintaxe());

    const Fabrica& fabrica = simulador.obterFabrica();

    std::cout << "Instante: " << fabrica.obterInstante() << std::endl;
    std::cout << "Creditos: " << fabrica.obterCreditos() << std::endl;

    std::cout << "Maquinas (" << fabrica.obterNumeroMaquinas() << "):" << std::endl;
    for (int i = 0; i < fabrica.obterLinhas(); i++) {
        for (int j = 0; j < fabrica.obterColunas(); j++) {
            const Maquina* maquina = fabrica.obterPosicao(i, j).obterMaquina();
            if (maquina == nullptr) continue;

            std::cout << "  " << maquina->obterTipo() << " em " << Fabrica::nomePosicao(i, j)
                      << " | direcao " << maquina->obterDirecao()
                      << " | engenheiros " << maquina->obterEngenheiros()
                      << " | " << maquina->obterResumo() << std::endl;
        }
    }

    std::cout << "Engenheiros: nenhum" << std::endl;

    std::cout << "Itens enviados para a Terra:";
    if (fabrica.obterEnviados().empty()) std::cout << " nenhum";
    std::cout << std::endl;
    for (const auto& enviado : fabrica.obterEnviados())
        std::cout << "  " << enviado.first << ": " << enviado.second << std::endl;

    return false;
}