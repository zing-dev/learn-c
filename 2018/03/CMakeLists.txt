cmake_minimum_required(VERSION 3.7.2)
project(03)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        03
        01/callback.c
        01/callback2.c 04/bubbleSort.c 04/max.c)

