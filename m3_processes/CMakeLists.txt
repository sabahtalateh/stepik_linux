cmake_minimum_required(VERSION 3.6)
project(m3_processes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp clon.c)
add_executable(m3_processes ${SOURCE_FILES} clon.c)