#include <string>
#include <stdexcept>
#include <random>

#include "Fabrica.h"

int Fabrica::sortear(int min, int max) {
    static std::mt19937 gerador(std::random_device{}());

    std::uniform_int_distribution<int> distribuicao(min, max);

    return distribuicao(gerador);
}

void Fabrica::colocar(char tipo, int qtd) {
    int linha = 0, coluna = 0, i = 0;

    while (i < qtd) {
        linha = sortear(0, linhasUsadas-1);
        coluna = sortear(0, colunasUsadas-1);

        if (grelha[linha][coluna].obterSimbolo() == ' ') {
            if (tipo == '%' || tipo == '$' || tipo == '~')
                grelha[linha][coluna] = Posicao(tipo, sortear(Settings::deposito_quantidade_min, Settings::deposito_quantidade_max));
            if (tipo == '#')
                grelha[linha][coluna] = Posicao(tipo, 0);
            i++;
        }
    }
}

Fabrica::Fabrica(int linhas, int colunas) : linhasUsadas(linhas), colunasUsadas(colunas), creditos(Settings::fabrica_creditos_iniciais), instante(0) {
    if ( (linhasUsadas <= 0 || linhasUsadas > Settings::fabrica_max_linhas) ||
         (colunasUsadas <= 0 || colunasUsadas > Settings::fabrica_max_colunas))
            throw std::invalid_argument("Numero de linhas ou colunas invalidas!");

    if ( (linhas * colunas) < (Settings::fabrica_num_crateras + Settings::fabrica_num_depositos_ferro + Settings::fabrica_num_depositos_gelo + Settings::fabrica_num_depositos_silicio))
        throw std::invalid_argument("Fabrica demasiado Pequena!");

    colocar('#', Settings::fabrica_num_crateras);
    colocar('%', Settings::fabrica_num_depositos_ferro);
    colocar('$', Settings::fabrica_num_depositos_silicio);
    colocar('~', Settings::fabrica_num_depositos_gelo);
}