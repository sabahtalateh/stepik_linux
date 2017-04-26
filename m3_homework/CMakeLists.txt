cmake_minimum_required(VERSION 3.6)
project(m3_homework)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES ppid.c proc_list.c pid_tree.c children_count.c daemon.c)
add_executable(m3_homework ${SOURCE_FILES})