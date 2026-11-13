#pragma once

#include <string>

class Item {
    public:
        Item(const std::string& nome, char simbolo, int valor);
        virtual ~Item();

        std::string obterNome() const;
        char obterSimbolo() const;
        int obterValor() const;

        virtual bool eMateriaPrima() const = 0;
        virtual Item* duplicar() const = 0;

    private:
        std::string nome;
        char simbolo;
        int valor;
};
