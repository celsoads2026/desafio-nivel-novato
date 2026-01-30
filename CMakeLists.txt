cmake_minimum_required(VERSION 4.1)
project(desafio_nivel_novato)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(.idea)

add_executable(desafio_nivel_novato
        main.c
        README.md)
