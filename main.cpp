#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "Interface/Simulador.h"

int main() {

    std::string linha;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, linha)) return 0;

        std::istringstream iss(linha);
        std::string comando;
        iss >> comando;

        if (comando == "fim") return 0;

        try {
            if (comando == "fabrica") {
                int linhas = 0, colunas = 0;

                if (!(iss >> linhas >> colunas)) {
                    std::cout << "Sintaxe: fabrica <linhas> <colunas>!" << std::endl;
                    continue;
                }

                Simulador simulador(linhas, colunas);
                simulador.executar();
                return 0;
            }

            if (comando == "carrega") {
                std::string nomeFicheiro;

                if (!(iss >> nomeFicheiro)) {
                    std::cout << "Sintaxe: carrega <nome-do-ficheiro>!" << std::endl;
                    continue;
                }

                Simulador simulador(nomeFicheiro);
                simulador.executar();
                return 0;
            }

            if (!comando.empty()) std::cout << "Primeiro crie a fabrica (fabrica ou carrega)!" << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

}
