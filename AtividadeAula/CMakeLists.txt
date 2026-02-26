cmake_minimum_required(VERSION 3.16)

project(AtividadeAula LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AtividadeAula main.cpp)

include(GNUInstallDirs)
install(TARGETS AtividadeAula
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
