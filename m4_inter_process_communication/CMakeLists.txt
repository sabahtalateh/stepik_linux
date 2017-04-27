cmake_minimum_required(VERSION 3.6)
project(m4_inter_process_communication)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES main.c pipe_example.c ipc.c signal.c)

add_executable(m4_inter_process_communication ${SOURCE_FILES})