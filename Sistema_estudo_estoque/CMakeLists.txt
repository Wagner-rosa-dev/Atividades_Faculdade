cmake_minimum_required(VERSION 3.16)

project(Sistema_estudo_estoque LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Sistema_estudo_estoque main.cpp
    source.cpp
    declara.h)

include(GNUInstallDirs)
install(TARGETS Sistema_estudo_estoque
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
