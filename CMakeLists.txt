cmake_minimum_required(VERSION 3.10)
project(magic_square)

add_executable(magic_square.exe main.cpp
state.cpp
grid.cpp
)

# target_compile_definitions(${TARGET} PRIVATE USE_MATH_DEFINES)
