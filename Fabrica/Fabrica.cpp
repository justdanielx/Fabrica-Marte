#include <string>
#include <stdexcept>
#include <random>
#include <fstream>

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
                //desnecessario o construtor faz a verificacao
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

Fabrica::Fabrica(const std::string& nomeFicheiro) : linhasUsadas(0), colunasUsadas(0), creditos(Settings::fabrica_creditos_iniciais), instante(0) {
    std::ifstream ficheiro(nomeFicheiro);
    std::string linha;

    if (!ficheiro)
        throw std::invalid_argument("Ficheiro nao encontrado!");

    if (!(ficheiro >> linhasUsadas >> colunasUsadas))
        throw std::invalid_argument("Formato do mapa invalido!");

    if ( (linhasUsadas <= 0 || linhasUsadas > Settings::fabrica_max_linhas) ||
         (colunasUsadas <= 0 || colunasUsadas > Settings::fabrica_max_colunas))
            throw std::invalid_argument("Numero de linhas ou colunas invalidas!");

    std::getline(ficheiro, linha);

    for (int i = 0; i < linhasUsadas; i++) {
        if (!std::getline(ficheiro, linha))
            throw std::invalid_argument("O mapa tem linhas a menos!");

        if (!linha.empty() && linha.back() == '\r') linha.pop_back(); //apaga o \r para Linux ou macOs (recomendacao do Claude)

        if (linha.size() != static_cast<size_t>(colunasUsadas)) //static_cast<size_t> transforma o data type de colunasUsadas em size_t, size() devcolve size_t (dataType int enorme e sem sinal)
            throw std::invalid_argument("Linha do mapa com tamanho errado!");

        for (int j = 0; j < colunasUsadas; j++) {
            char simbolo = linha[j];

            if (simbolo == '.') simbolo = ' ';
            grelha[i][j] = Posicao(simbolo, sortear(Settings::deposito_quantidade_min, Settings::deposito_quantidade_max));
            //nao e necessario verificar se é cratera o construtor faz isso
        }
    }
}

int Fabrica::obterLinhas() const {return linhasUsadas;}
int Fabrica::obterColunas() const {return colunasUsadas;}
int Fabrica::obterCreditos() const {return creditos;}
int Fabrica::obterInstante() const {return instante;}

const Posicao& Fabrica::obterPosicao(int linha, int coluna) const {
    if ( (linha < 0 || linha >= linhasUsadas) ||
         (coluna < 0 || coluna >= colunasUsadas))
            throw std::out_of_range("Posicao fora da fabrica!");

    return grelha[linha][coluna];
}