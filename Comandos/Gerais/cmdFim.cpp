#include <iostream>
#include <stdexcept>

#include "Comandos/Gerais/cmdFim.h"
#include "Interface/Simulador.h"

cmdFim::cmdFim() : Comando("fim", "fim",
    "Termina o programa, libertando todos os recursos.",
    "fim") {}

bool cmdFim::precisaDeFabrica() const {return false;}

bool cmdFim::executa(Simulador& simulador, std::istringstream& parametros) const {
    if (!semMaisParametros(parametros)) throw std::invalid_argument(erroSintaxe());

    std::cout << "A terminar o simulador!" << std::endl;
    simulador.terminar();
    return false;
}