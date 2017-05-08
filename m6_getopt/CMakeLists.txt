cmake_minimum_required(VERSION 3.6)
project(m6_getopt)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES getopt.c hw_1/solution.c)
add_executable(m6_getopt ${SOURCE_FILES} hw_1/solution.c)