cmake_minimum_required(VERSION 3.6)
project(m4_homework)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c long_text_util.c symbol_count.c ex1/solution.c multiplexing.c ex2/test.c ex3/solution.c ex5_shared_memory/solution.c ex5_shared_memory/shm_server.c ex5_shared_memory/solution_server.c)
add_executable(m4_homework ${SOURCE_FILES})