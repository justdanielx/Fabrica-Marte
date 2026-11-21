#pragma once

#include <string>
#include <vector>

#include "Fabrica/Fabrica.h"

class Comando;

class Simulador {
    public:
        Simulador();
        Simulador(const Simulador&) = delete;
        Simulador& operator=(const Simulador&) = delete;
        ~Simulador();

        void executar();
        void processar(const std::string& linha);
        void terminar();

        bool temFabrica() const;
        void criarFabrica(Fabrica* nova);
        Fabrica& obterFabrica();
        const Fabrica& obterFabrica() const;

        const Comando* procurarComando(const std::string& nome) const;
        std::string obterListaComandos() const;

        std::string obterDesenho() const;
        void mostrar() const;

    private:
        Fabrica* fabrica;
        std::vector<Comando*> comandos;
        bool aTerminar;
};
