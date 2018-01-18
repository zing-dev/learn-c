cmake_minimum_required(VERSION 3.7.2)
project(2018)

set(CMAKE_CXX_STANDARD 11)

add_executable(demo
        demo/client.c demo/server.c
        demo/printSocketOptions.c
        )

