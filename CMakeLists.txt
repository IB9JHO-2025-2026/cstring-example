# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProgram)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra)

set(SRC_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/cstring.cpp)
add_executable(my_program ${SRC_FILES})