cmake_minimum_required(VERSION 3.16)

project(Atividade9Lista4-06-03-26 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Atividade9Lista4-06-03-26 main.cpp)

include(GNUInstallDirs)
install(TARGETS Atividade9Lista4-06-03-26
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
