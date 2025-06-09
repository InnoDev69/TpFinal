cmake_minimum_required(VERSION 3.10)
project(TpFinal)

# Especifica el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Agrega los directorios de include
include_directories(${PROJECT_SOURCE_DIR}/data)
include_directories(${PROJECT_SOURCE_DIR}/functions)

# Crea una lista con todos los archivos fuente
set(SOURCES
    main.cpp
    functions/game_display.cpp
    functions/cuestions.cpp
    functions/utils.cpp
    functions/logica_batalla.cpp
    functions/tienda.cpp
)

# Crea el ejecutable
add_executable(game ${SOURCES})