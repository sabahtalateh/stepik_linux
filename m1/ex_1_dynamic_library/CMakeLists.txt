cmake_minimum_required(VERSION 3.6)
project(dynamic_library)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c solution.c)
add_executable(dynamic_library ${SOURCE_FILES})