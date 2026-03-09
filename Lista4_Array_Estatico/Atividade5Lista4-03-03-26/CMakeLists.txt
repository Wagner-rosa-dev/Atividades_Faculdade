cmake_minimum_required(VERSION 3.16)

project(Atividade5Lista4-03-03-26 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Atividade5Lista4-03-03-26 main.cpp)

include(GNUInstallDirs)
install(TARGETS Atividade5Lista4-03-03-26
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
