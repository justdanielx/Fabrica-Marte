#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Simulador.h"

Simulador::Simulador(int linhas, int colunas) : fabrica(linhas, colunas) {}
Simulador::Simulador(const std::string& nomeFicheiro) : fabrica(nomeFicheiro) {}

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

std::string Simulador::descreverPosicao(const std::string& posicao) const {
    if (posicao.size() != 2)
        return "Posicao invalida! Use duas letras (ex: ce)!";

    int linha = posicao[0] - 'a';
    int coluna = posicao[1] - 'a';

    //nao funciona com AB por exemplo apenas com aa, indica o erro de out of range abaixo (problema a melhorar)

    try {
        return posicao + ": " + fabrica.obterPosicao(linha, coluna).obterDescricao();
    } catch (const std::out_of_range& e) {
        return e.what();
    }
}

void Simulador::executar() {
    std::string linha;

    std::cout << obterSimulador();

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, linha)) return;

        std::istringstream iss(linha);
        std::string comando, posicao;
        iss >> comando;

        if (comando == "fim") return;

        if (comando == "lposicao") {
            if (iss >> posicao) std::cout << descreverPosicao(posicao) << std::endl;
            else std::cout << "Sintaxe: lposicao <lc>!" << std::endl;
        } else if (comando == "fabrica" || comando == "carrega") {
            std::cout << "A fabrica ja foi criada!" << std::endl;
        } else if (!comando.empty()) {
            std::cout << "Comando desconhecido!" << std::endl;
        }
    }
}