cmake_minimum_required(VERSION 3.6)
project(m5_network)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES resolve.c udp_client.c tcp.c hw_1/solution.c hw_2/solution.c)
add_executable(m5_network ${SOURCE_FILES} resolve.c udp_client.c hw_1/solution.c)