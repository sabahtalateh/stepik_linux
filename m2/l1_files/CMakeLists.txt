cmake_minimum_required(VERSION 3.6)
project(l1_files)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES files.c dirs.c)
add_executable(l1_files ${SOURCE_FILES} dirs.c)