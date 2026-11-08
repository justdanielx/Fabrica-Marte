#include <string>

#include "Simulador.h"

Simulador::Simulador(int linhas, int colunas) : fabrica(linhas, colunas) {}

std::string Simulador::obterSimulador() const {
    int linhas = fabrica.obterLinhas();
    int colunas = fabrica.obterColunas();

    Ecra ecra(linhas+3, colunas+3 + 1 + 20);
    ecra.moldura(0, 0, linhas+3, colunas+3);

    for (int i = 0; i < linhas; i++)
        ecra.escrever('A' + i, i+2, 1);

    for (int i = 0; i < colunas; i++)
        ecra.escrever('A' + i, 1, i+2);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            ecra.escrever(fabrica.obterPosicao(i, j).obterSimbolo(), i+2, j+2);
    }

    ecra.moldura(0, colunas+4, 4, 20);
    ecra.escrever("Instante: " + std::to_string(fabrica.obterInstante()), 1, colunas + 5);
    ecra.escrever("Creditos: " + std::to_string(fabrica.obterCreditos()), 2, colunas + 5);

    return ecra.obterBuffer();
}