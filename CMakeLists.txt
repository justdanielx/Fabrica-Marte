cmake_minimum_required(VERSION 3.20)
project(Fabrica-Marte CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Fabrica-Marte
        main.cpp
        Interface/Ecra.cpp
        Interface/Simulador.cpp
        Fabrica/Engenheiro.cpp
        Fabrica/Fabrica.cpp
        Fabrica/Posicao.cpp
        Maquinas/Lancador.cpp
        Maquinas/Maquina.cpp
        Maquinas/Oficina.cpp
        Maquinas/Perfuradora.cpp
        Maquinas/Refinaria.cpp
        Maquinas/Silo.cpp
        Maquinas/Transportador.cpp
        Itens/Item.cpp
        Itens/MateriaPrima.cpp
        Itens/ProdutoRefinado.cpp
        Comandos/Comando.cpp
        Comandos/Engenheiros/cmdAtribui.cpp
        Comandos/Engenheiros/cmdContrata.cpp
        Comandos/Engenheiros/cmdDespede.cpp
        Comandos/Fabrica/cmdCarrega.cpp
        Comandos/Fabrica/cmdFabrica.cpp
        Comandos/Gerais/cmdAjuda.cpp
        Comandos/Gerais/cmdExecuta.cpp
        Comandos/Gerais/cmdFim.cpp
        Comandos/Gerais/cmdGrava.cpp
        Comandos/Gerais/cmdRecupera.cpp
        Comandos/Listagem/cmdEstado.cpp
        Comandos/Listagem/cmdLposicao.cpp
        Comandos/Maquinas/cmdCompra.cpp
        Comandos/Maquinas/cmdMelhora.cpp
        Comandos/Maquinas/cmdRoda.cpp
        Comandos/Maquinas/cmdVende.cpp
        Comandos/Tempo/cmdAvanca.cpp
)

target_include_directories(Fabrica-Marte PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(Fabrica-Marte PRIVATE -Wall -Wextra -pedantic)

configure_file(${CMAKE_SOURCE_DIR}/mapa1.txt ${CMAKE_CURRENT_BINARY_DIR}/mapa1.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/teste1.txt ${CMAKE_CURRENT_BINARY_DIR}/teste1.txt COPYONLY)