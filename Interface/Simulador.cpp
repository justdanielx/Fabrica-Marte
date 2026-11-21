#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>

#include "Interface/Simulador.h"
#include "Interface/Ecra.h"
#include "Comandos/ComandoFabrica.h"
#include "Comandos/ComandoCarrega.h"
#include "Comandos/ComandoAvanca.h"
#include "Comandos/ComandoCompra.h"
#include "Comandos/ComandoVende.h"
#include "Comandos/ComandoRoda.h"
#include "Comandos/ComandoMelhora.h"
#include "Comandos/ComandoContrata.h"
#include "Comandos/ComandoAtribui.h"
#include "Comandos/ComandoDespede.h"
#include "Comandos/ComandoEstado.h"
#include "Comandos/ComandoLposicao.h"
#include "Comandos/ComandoGrava.h"
#include "Comandos/ComandoRecupera.h"
#include "Comandos/ComandoExecuta.h"
#include "Comandos/ComandoAjuda.h"
#include "Comandos/ComandoFim.h"

Simulador::Simulador() : fabrica(nullptr), aTerminar(false), ficheirosAbertos(0) {
    comandos.push_back(new ComandoFabrica());
    comandos.push_back(new ComandoCarrega());
    comandos.push_back(new ComandoAvanca());
    comandos.push_back(new ComandoCompra());
    comandos.push_back(new ComandoVende());
    comandos.push_back(new ComandoRoda());
    comandos.push_back(new ComandoMelhora());
    comandos.push_back(new ComandoContrata());
    comandos.push_back(new ComandoAtribui());
    comandos.push_back(new ComandoDespede());
    comandos.push_back(new ComandoEstado());
    comandos.push_back(new ComandoLposicao());
    comandos.push_back(new ComandoGrava());
    comandos.push_back(new ComandoRecupera());
    comandos.push_back(new ComandoExecuta());
    comandos.push_back(new ComandoAjuda());
    comandos.push_back(new ComandoFim());
}

Simulador::~Simulador() {
    delete fabrica;

    for (Comando* comando : comandos)
        delete comando;
}

void Simulador::executar() {
    std::string linha;

    std::cout << "Fabrica em Marte - escreva ajuda para ver os comandos!" << std::endl;

    while (!aTerminar) {
        std::cout << "> ";
        if (!std::getline(std::cin, linha)) return;

        processar(linha);
    }
}

void Simulador::processar(const std::string& linha) {
    std::istringstream iss(linha);
    std::string nome;

    if (!(iss >> nome)) return;

    const Comando* comando = procurarComando(nome);

    if (comando == nullptr) {
        std::cout << "Comando desconhecido! Escreva ajuda para ver os comandos!" << std::endl;
        return;
    }

    if (comando->precisaDeFabrica() && fabrica == nullptr) {
        std::cout << "Primeiro crie a fabrica (fabrica ou carrega)!" << std::endl;
        return;
    }

    try {
        if (comando->executa(*this, iss)) mostrar();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Simulador::executarFicheiro(const std::string& nomeFicheiro) {
    const int MAX_FICHEIROS = 10;

    if (ficheirosAbertos >= MAX_FICHEIROS) throw std::runtime_error("Demasiados ficheiros executados uns dentro dos outros!");

    std::ifstream ficheiro(nomeFicheiro);
    std::string linha;

    if (!ficheiro) throw std::invalid_argument("Ficheiro " + nomeFicheiro + " nao encontrado!");

    ficheirosAbertos++;
    while (!aTerminar && std::getline(ficheiro, linha)) {
        if (!linha.empty() && linha.back() == '\r') linha.pop_back();

        std::cout << "> " << linha << std::endl;
        processar(linha);
    }
    ficheirosAbertos--;
}

void Simulador::terminar() {aTerminar = true;}

bool Simulador::temFabrica() const {return fabrica != nullptr;}

void Simulador::criarFabrica(Fabrica* nova) {
    if (fabrica != nullptr) {
        delete nova;
        throw std::logic_error("A fabrica ja foi criada!");
    }

    fabrica = nova;
}

Fabrica& Simulador::obterFabrica() {
    if (fabrica == nullptr) throw std::logic_error("Ainda nao existe fabrica!");
    return *fabrica;
}

const Fabrica& Simulador::obterFabrica() const {
    if (fabrica == nullptr) throw std::logic_error("Ainda nao existe fabrica!");
    return *fabrica;
}

const Comando* Simulador::procurarComando(const std::string& nome) const {
    for (const Comando* comando : comandos)
        if (comando->obterNome() == nome) return comando;

    return nullptr;
}

std::string Simulador::obterListaComandos() const {
    std::ostringstream oss;

    for (const Comando* comando : comandos)
        oss << comando->obterSintaxe() << std::endl;

    return oss.str();
}

std::string Simulador::obterDesenho() const {
    const int LARGURA_PAINEL = 36;
    const int MAX_RESUMO = Settings::ecra_max_linhas - 8;

    int linhas = fabrica->obterLinhas();
    int colunas = fabrica->obterColunas();
    const std::vector<std::string>& resumo = fabrica->obterResumo();

    int linhasResumo = static_cast<int>(resumo.size());
    if (linhasResumo == 0) linhasResumo = 1;
    if (linhasResumo > MAX_RESUMO) linhasResumo = MAX_RESUMO;

    int alturaPainel = 7 + linhasResumo + 1;
    int altura = linhas + 3;
    if (alturaPainel > altura) altura = alturaPainel;

    Ecra ecra(altura, colunas + 3 + 1 + LARGURA_PAINEL);
    ecra.moldura(0, 0, linhas + 3, colunas + 3);

    for (int i = 0; i < linhas; i++)
        ecra.escrever('A' + i, i + 2, 1);

    for (int i = 0; i < colunas; i++)
        ecra.escrever('A' + i, 1, i + 2);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            ecra.escrever(fabrica->obterPosicao(i, j).obterSimboloEcra(), i + 2, j + 2);
    }

    int colunaPainel = colunas + 5;
    ecra.moldura(0, colunas + 4, alturaPainel, LARGURA_PAINEL);
    ecra.escrever("Instante: " + std::to_string(fabrica->obterInstante()), 1, colunaPainel);
    ecra.escrever("Creditos: " + std::to_string(fabrica->obterCreditos()), 2, colunaPainel);
    ecra.escrever("Maquinas: " + std::to_string(fabrica->obterNumeroMaquinas()), 3, colunaPainel);
    ecra.escrever("Engenheiros: 0", 4, colunaPainel);
    ecra.escrever("No ultimo instante:", 6, colunaPainel);

    if (resumo.empty()) ecra.escrever("nada a registar", 7, colunaPainel);

    for (int i = 0; i < linhasResumo && i < static_cast<int>(resumo.size()); i++)
        ecra.escrever(resumo[i], 7 + i, colunaPainel);

    return ecra.obterBuffer();
}

void Simulador::mostrar() const {
    if (fabrica != nullptr) std::cout << obterDesenho();
}
