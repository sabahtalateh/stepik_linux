cmake_minimum_required(VERSION 3.6)
project(m4_homework)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c long_text_util.c symbol_count.c ex1/solution.c)
add_executable(m4_homework ${SOURCE_FILES})