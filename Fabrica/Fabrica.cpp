#include <string>
#include <stdexcept>
#include <random>
#include <fstream>

#include "Fabrica.h"
#include "Maquinas/Maquina.h"
#include "Itens/Item.h"

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

bool Fabrica::dentro(int linha, int coluna) const {
    return (linha >= 0 && linha < linhasUsadas && coluna >= 0 && coluna < colunasUsadas);
}

const Posicao& Fabrica::obterPosicao(int linha, int coluna) const {
    if (!dentro(linha, coluna))
        throw std::out_of_range("Posicao fora da fabrica!");

    return grelha[linha][coluna];
}

Posicao& Fabrica::posicaoEm(int linha, int coluna) {
    if (!dentro(linha, coluna))
        throw std::out_of_range("Posicao fora da fabrica!");

    return grelha[linha][coluna];
}

int Fabrica::obterNumeroMaquinas() const {
    int total = 0;

    for (int i = 0; i < linhasUsadas; i++)
        for (int j = 0; j < colunasUsadas; j++)
            if (grelha[i][j].temMaquina()) total++;

    return total;
}

const std::vector<std::string>& Fabrica::obterResumo() const {return resumo;}
const std::map<std::string, int>& Fabrica::obterEnviados() const {return enviados;}

void Fabrica::comprar(char tipo, int linha, int coluna, char direcao) {
    Posicao& posicao = posicaoEm(linha, coluna);

    if (posicao.eCratera()) throw std::invalid_argument("Nao e possivel colocar maquinas em crateras!");
    if (posicao.temMaquina()) throw std::invalid_argument("A posicao " + nomePosicao(linha, coluna) + " ja esta ocupada!");

    Maquina* nova = Maquina::criar(tipo, direcao);

    if (nova->obterCusto() > creditos) {
        int custo = nova->obterCusto();
        delete nova;
        throw std::invalid_argument("Creditos insuficientes! Custa " + std::to_string(custo) + " e tem " + std::to_string(creditos) + "!");
    }

    creditos -= nova->obterCusto();
    posicao.colocarMaquina(nova);
}

int Fabrica::vender(int linha, int coluna) {
    Posicao& posicao = posicaoEm(linha, coluna);

    if (!posicao.temMaquina()) throw std::invalid_argument("Nao existe nenhuma maquina em " + nomePosicao(linha, coluna) + "!");

    int valor = posicao.obterMaquina()->obterCusto() * Settings::maquina_percentagem_venda / 100;
    creditos += valor;
    posicao.removerMaquina();

    return valor;
}

void Fabrica::rodar(int linha, int coluna, char direcao) {
    Posicao& posicao = posicaoEm(linha, coluna);

    if (!posicao.temMaquina()) throw std::invalid_argument("Nao existe nenhuma maquina em " + nomePosicao(linha, coluna) + "!");
    if (!posicao.obterMaquina()->rodar(direcao)) throw std::invalid_argument("Direcao invalida! Use c, b, e ou d!");
}

void Fabrica::avancarInstante() {
    instante++;
    resumo.clear();

    for (int i = 0; i < linhasUsadas; i++)
        for (int j = 0; j < colunasUsadas; j++)
            if (grelha[i][j].temMaquina())
                grelha[i][j].obterMaquina()->atuar(*this, i, j);
}

bool Fabrica::entregar(int linha, int coluna, char direcao, Item* item) {
    int linhaVizinha = linha, colunaVizinha = coluna;

    if (direcao == 'c') linhaVizinha--;
    else if (direcao == 'b') linhaVizinha++;
    else if (direcao == 'e') colunaVizinha--;
    else if (direcao == 'd') colunaVizinha++;

    if (!dentro(linhaVizinha, colunaVizinha)) return false;

    Posicao& vizinha = grelha[linhaVizinha][colunaVizinha];
    if (!vizinha.temMaquina()) return false;

    int chegadaAnterior = item->obterInstanteChegada();
    item->marcarChegada(instante);

    if (vizinha.obterMaquina()->aceitarItem(item)) return true;

    item->marcarChegada(chegadaAnterior);
    return false;
}

char Fabrica::extrairMateriaPrima(int linha, int coluna) {
    Posicao& posicao = posicaoEm(linha, coluna);
    char deposito = posicao.extrair();

    if (deposito != ' ' && !posicao.eDeposito())
        registar("deposito esgotado em " + nomePosicao(linha, coluna));

    return deposito;
}

void Fabrica::registar(const std::string& evento) {resumo.push_back(evento);}

bool Fabrica::sortearProbabilidade(int percentagem) {
    return (sortear(1, 100) <= percentagem);
}

std::string Fabrica::nomePosicao(int linha, int coluna) {
    std::string nome;

    nome += static_cast<char>('a' + linha);
    nome += static_cast<char>('a' + coluna);
    return nome;
}
