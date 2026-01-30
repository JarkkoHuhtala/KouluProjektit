cmake_minimum_required(VERSION 3.16)

project(Pankkitili LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Pankkitili main.cpp
    Pankkitili.h
    Pankkitili.cpp
    Asiakas.h
    Asiakas.cpp)

include(GNUInstallDirs)
install(TARGETS Pankkitili
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
