#include <iostream>
#include <stdexcept>

#include "Comandos/ComandoFim.h"
#include "Interface/Simulador.h"

ComandoFim::ComandoFim() : Comando("fim", "fim",
    "Termina o programa, libertando todos os recursos.",
    "fim") {}

bool ComandoFim::precisaDeFabrica() const {return false;}

bool ComandoFim::executa(Simulador& simulador, std::istringstream& parametros) const {
    if (!semMaisParametros(parametros)) throw std::invalid_argument(erroSintaxe());

    std::cout << "A terminar o simulador!" << std::endl;
    simulador.terminar();
    return false;
}
