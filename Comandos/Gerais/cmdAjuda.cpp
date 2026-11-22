#include <iostream>
#include <stdexcept>

#include "Comandos/Gerais/cmdAjuda.h"
#include "Interface/Simulador.h"

cmdAjuda::cmdAjuda() : Comando("ajuda", "ajuda [comando]",
    "Sem parametro, lista todos os comandos com a sua sintaxe resumida.\n"
    "Com o nome de um comando, mostra a ajuda detalhada desse comando.\n"
    "Falha se o comando indicado nao existir.",
    "ajuda compra") {}

bool cmdAjuda::precisaDeFabrica() const {return false;}

bool cmdAjuda::executa(Simulador& simulador, std::istringstream& parametros) const {
    std::string nome;

    if (!lerPalavra(parametros, nome)) {
        std::cout << simulador.obterListaComandos();
        return false;
    }

    if (!semMaisParametros(parametros)) throw std::invalid_argument(erroSintaxe());

    const Comando* comando = simulador.procurarComando(nome);
    if (comando == nullptr) throw std::invalid_argument("O comando " + nome + " nao existe!");

    std::cout << comando->obterAjuda() << std::endl;
    return false;
}