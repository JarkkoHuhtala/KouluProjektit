cmake_minimum_required(VERSION 3.16)

project(Viikko3Teht LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Viikko3Teht main.cpp
    Chef.h
    ItalianChef.h
    ItalianChef.cpp
    Chef.cpp
)

include(GNUInstallDirs)
install(TARGETS Viikko3Teht
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
