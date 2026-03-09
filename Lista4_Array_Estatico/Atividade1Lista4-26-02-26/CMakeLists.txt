cmake_minimum_required(VERSION 3.16)

project(Atividade1Lista4-26-02-26 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Atividade1Lista4-26-02-26 main.cpp)

include(GNUInstallDirs)
install(TARGETS Atividade1Lista4-26-02-26
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
