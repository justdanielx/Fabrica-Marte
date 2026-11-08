cmake_minimum_required(VERSION 3.20)
project(FabricaMarte CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FabricaMarte
        main.cpp
        Interface/Ecra.cpp
        Interface/Simulador.cpp
        Fabrica/Fabrica.cpp
        Fabrica/Posicao.cpp
)

target_include_directories(FabricaMarte PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(FabricaMarte PRIVATE -Wall -Wextra -pedantic)
