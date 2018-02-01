cmake_minimum_required(VERSION 3.7.2)
project(1)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        02
#        01/tsd.c
        01/mutex.c 01/server.c 01/client.c 01/isalpha.c 01/tcp/server.c 01/tcp/client.c 01/udp/client.c 01/udp/server.c)
