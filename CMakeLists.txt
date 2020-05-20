cmake_minimum_required(VERSION 3.7.2)
project(learn-c)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(main main.c)
add_subdirectory(linux)
add_subdirectory(csapp)
