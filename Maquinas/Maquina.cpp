#include <stdexcept>
#include <sstream>

#include "Maquinas/Maquina.h"
#include "Maquinas/Perfuradora.h"
#include "Maquinas/Transportador.h"
#include "Maquinas/Refinaria.h"
#include "Maquinas/Oficina.h"
#include "Maquinas/Silo.h"
#include "Maquinas/Lancador.h"
#include "Settings.h"

Maquina::Maquina(int custo, char direcao) : custo(custo), direcao(direcao), engenheiros(0) {
    if (!direcaoValida(direcao))
        throw std::invalid_argument("Direcao invalida! Use c, b, e ou d!");
}

Maquina::Maquina(const Maquina& outra) : custo(outra.custo), direcao(outra.direcao), engenheiros(0) {}

Maquina::~Maquina() {}

Maquina& Maquina::operator=(const Maquina& outra) {
    custo = outra.custo;
    direcao = outra.direcao;
    engenheiros = 0;

    return *this;
}

Maquina* Maquina::criar(char tipo, char direcao) {
    if (tipo == 'p') return new Perfuradora(direcao);
    if (tipo == 't') return new Transportador(direcao);
    if (tipo == 'r') return new Refinaria(direcao);
    if (tipo == 'o') return new Oficina(direcao);
    if (tipo == 's') return new Silo(direcao);
    if (tipo == 'l') return new Lancador(direcao);

    throw std::invalid_argument("Tipo de maquina invalido! Use p, t, r, o, s ou l!");
}

bool Maquina::direcaoValida(char direcao) {
    return (direcao == 'c' || direcao == 'b' || direcao == 'e' || direcao == 'd');
}

bool Maquina::melhorar() {return false;}
int Maquina::obterCustoMelhoria() const {return 0;}

int Maquina::obterCusto() const {return custo;}
char Maquina::obterDirecao() const {return direcao;}

bool Maquina::rodar(char novaDirecao) {
    if (!direcaoValida(novaDirecao)) return false;

    direcao = novaDirecao;
    return true;
}

int Maquina::obterEngenheiros() const {return engenheiros;}
void Maquina::adicionarEngenheiro() {engenheiros++;}

void Maquina::removerEngenheiro() {
    if (engenheiros > 0) engenheiros--;
}

int Maquina::duracaoComEngenheiros(int duracaoBase) const {
    int duracao = duracaoBase - engenheiros * Settings::engenheiro_reducao_duracao;

    if (duracao < Settings::maquina_duracao_minima) duracao = Settings::maquina_duracao_minima;
    return duracao;
}

std::string Maquina::descricaoBase() const {
    std::ostringstream oss;

    oss << obterTipo() << " | direcao " << direcao << " | engenheiros " << engenheiros;
    return oss.str();
}
