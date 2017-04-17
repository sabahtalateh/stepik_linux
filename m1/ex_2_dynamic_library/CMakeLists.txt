cmake_minimum_required(VERSION 3.6)
project(ex_2_dynamic_library)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES solution.c lib.c lib.h)
add_executable(ex_2_dynamic_library ${SOURCE_FILES})