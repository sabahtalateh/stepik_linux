cmake_minimum_required(VERSION 3.6)
project(l1)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES hello.c hello.h main.c)
add_executable(l1 ${SOURCE_FILES})