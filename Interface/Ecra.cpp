#include <string>
#include <stdexcept>
#include <sstream>

#include "Ecra.h"

void Ecra::limpar() {
    for (int i = 0; i < Settings::ecra_max_linhas; i++)
        for (int j = 0; j < Settings::ecra_max_colunas; j++)
            buffer[i][j] = ' ';
}

Ecra::Ecra(int linhas, int colunas) : linhasUsadas(linhas), colunasUsadas(colunas), linhaCursor(0), colunaCursor(0) {
    if ( (linhasUsadas <= 0 || linhasUsadas > Settings::ecra_max_linhas) || 
         (colunasUsadas <= 0 || colunasUsadas > Settings::ecra_max_colunas) ) {
            throw std::invalid_argument("Numero de linhas ou colunas invalidas!");
    }

    limpar();
}



bool Ecra::posicionar(int linha, int coluna) {
    if ( (linha < 0 || linha >= linhasUsadas) || 
         (coluna < 0 || coluna >= colunasUsadas)) {
            return false;
    }

    linhaCursor = linha;
    colunaCursor = coluna;

    return true;
}

bool Ecra::escrever(const std::string& texto) {
    for (size_t i = 0; i < texto.size(); i++) {
        if (colunaCursor < colunasUsadas) {
            buffer[linhaCursor][colunaCursor] = texto[i];
            colunaCursor++;
        } else {
            return false;   /*Decidi nao complicar, mas assim nao existe maneira de saber
                            se o false significa que nao foi possivel escrever de todo 
                            ou se escreveu mas ficou pela metade ou se na versoa de 
                            indicar uma posicao especifica se nao foi uma posicao valida*/
        }
    }

    return true;
}


bool Ecra::escrever(const std::string& texto, int linha, int coluna) {
    if (!posicionar(linha, coluna)) 
        return false;

    return escrever(texto);
}

bool Ecra::escrever(const char caracter) {
    if (colunaCursor < colunasUsadas) {
        buffer[linhaCursor][colunaCursor] = caracter;
        colunaCursor++;
    } else {
        return false;
    }

    return true;
}

bool Ecra::escrever(const char caracter, int linha, int coluna) {
    if (!posicionar(linha, coluna)) 
        return false;

    return escrever(caracter);
}



bool Ecra::moldura(int linha, int coluna, int altura, int largura) {
    if (altura < 2 || largura < 2)
        return false;

    int ultLinha = linha + altura - 1;
    int ultColuna = coluna + largura - 1;

    for (int i = coluna; i <= ultColuna; i++) {
        escrever('-', linha, i);
        escrever('-', ultLinha, i);
    }

    for (int i = linha; i <= ultLinha; i++) {
        escrever('|', i, coluna);
        escrever('|', i, ultColuna);
    }

    escrever('+', linha, coluna);
    escrever('+', ultLinha, coluna);
    escrever('+', linha, ultColuna);
    escrever('+', ultLinha, ultColuna);

    return true;
}

std::string Ecra::obterBuffer() const {
    std::ostringstream oss;

    for (int i = 0; i < linhasUsadas; i++) {
        for (int j = 0; j < colunasUsadas; j++)
            oss << buffer[i][j];
        oss << '\n';
    }

    return oss.str();
}