cmake_minimum_required(VERSION 3.20)
project(Fabrica-Marte CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Fabrica-Marte
        main.cpp
        Interface/Ecra.cpp
        Interface/Simulador.cpp
        Fabrica/Fabrica.cpp
        Fabrica/Posicao.cpp
        Comandos/Comando.cpp
        Fabrica/Engenheiro.cpp
        Itens/Item.cpp
        Itens/MateriaPrima.cpp
        Itens/ProdutoRefinado.cpp
        Maquinas/Lancador.cpp
        Maquinas/Maquina.cpp
        Maquinas/Oficina.cpp
        Maquinas/Perfuradora.cpp
        Maquinas/Refinaria.cpp
        Maquinas/Silo.cpp
        Maquinas/Transportador.cpp
)

target_include_directories(Fabrica-Marte PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(Fabrica-Marte PRIVATE -Wall -Wextra -pedantic)
