cmake_minimum_required(VERSION 3.6)
project(proc_fs)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES hello.c)
add_executable(proc_fs ${SOURCE_FILES})