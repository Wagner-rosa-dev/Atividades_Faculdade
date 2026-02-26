cmake_minimum_required(VERSION 3.16)

project(Atividade21Lista1-21-02-26 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Atividade21Lista1-21-02-26 main.cpp)

include(GNUInstallDirs)
install(TARGETS Atividade21Lista1-21-02-26
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
