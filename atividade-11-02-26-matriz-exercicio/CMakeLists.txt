cmake_minimum_required(VERSION 3.16)

project(atividade-11-02-26-matriz-exercicio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(atividade-11-02-26-matriz-exercicio main.cpp)

include(GNUInstallDirs)
install(TARGETS atividade-11-02-26-matriz-exercicio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
