
#Se indica la versión mínima.
cmake_minimum_required(VERSION 3.10)
# El nombre del proyecto que puede ser cualquier nombre
project(vectores)

# Se indica donde encontrar los "headers" para este proyecto
#Aqui se encuentran los archivos .hpp
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                   )

# Se pueden definir variables que apunten a archivos grupos de archivos
#Aquí se encuentra el archivo VecR3.cpp
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# En este caso se agregan los archivos en la carpeta src
# a las fuentes para construir el ejecutable
add_executable(main ${sources} main.cpp)
