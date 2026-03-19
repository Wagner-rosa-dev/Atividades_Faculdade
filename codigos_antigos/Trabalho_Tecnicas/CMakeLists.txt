cmake_minimum_required(VERSION 3.16)

project(Trabalho_Tecnicas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Trabalho_Tecnicas main.cpp)

include(GNUInstallDirs)
install(TARGETS Trabalho_Tecnicas
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
