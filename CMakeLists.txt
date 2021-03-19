cmake_minimum_required(VERSION 3.7.2)
project(learn-c)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -Wall")

include_directories(include)

add_executable(main main.c)
add_subdirectory(linux)
add_subdirectory(books)
add_subdirectory(examples)
