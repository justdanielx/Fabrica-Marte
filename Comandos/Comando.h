#pragma once

#include <string>
#include <sstream>

class Simulador;

class Comando {
    public:
        Comando(const std::string& nome, const std::string& sintaxe, const std::string& descricao, const std::string& exemplo);
        virtual ~Comando();

        std::string obterNome() const;
        std::string obterSintaxe() const;
        std::string obterAjuda() const;

        virtual bool precisaDeFabrica() const;
        virtual bool executa(Simulador& simulador, std::istringstream& parametros) const = 0;

    protected:
        std::string erroSintaxe() const;

        static bool lerPalavra(std::istringstream& parametros, std::string& palavra);
        static bool lerInteiro(std::istringstream& parametros, int& valor);
        static bool lerInteiroOpcional(std::istringstream& parametros, int& valor);
        static bool lerPosicao(std::istringstream& parametros, int& linha, int& coluna);
        static bool lerDirecao(std::istringstream& parametros, char& direcao);
        static bool semMaisParametros(std::istringstream& parametros);

    private:
        std::string nome;
        std::string sintaxe;
        std::string descricao;
        std::string exemplo;

        static bool converterInteiro(const std::string& texto, int& valor);
};
