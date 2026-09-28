cmake_minimum_required(VERSION 3.16)

project(Trabalho_Estruturas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Trabalho_Estruturas main.cpp
    fila.h
    pilha.h
    pilha.cpp
    fila.cpp)

include(GNUInstallDirs)
install(TARGETS Trabalho_Estruturas
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
