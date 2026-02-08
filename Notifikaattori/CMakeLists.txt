cmake_minimum_required(VERSION 3.16)

project(Notifikaattori LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Notifikaattori main.cpp
    Seuraaja.h
    Notifikaattori.h
    Notifikaattori.cpp
    Seuraaja.cpp)

include(GNUInstallDirs)
install(TARGETS Notifikaattori
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
