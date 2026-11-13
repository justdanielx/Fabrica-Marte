#pragma once

#include <string>
#include <sstream>

class Simulador;

class Comando {
    public:
        virtual ~Comando();

        virtual std::string obterNome() const = 0;
        virtual std::string obterSintaxe() const = 0;
        virtual std::string obterAjuda() const = 0;
        virtual bool executa(Simulador& simulador, std::istringstream& parametros) = 0;
};
