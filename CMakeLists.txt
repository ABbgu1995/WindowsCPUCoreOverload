cmake_minimum_required(VERSION 3.26)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(CPU_Overloader main.c)
target_link_libraries(CPU_Overloader PRIVATE winmm)