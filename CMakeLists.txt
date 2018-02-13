cmake_minimum_required(VERSION 3.7.2)
project(learc-c)

set(CMAKE_CXX_STANDARD 11)

#add_executable(
#        learc-c
#        2018/01/07/1.c
#        2018/01/07/2.c
#)

#add_library(2018)
add_subdirectory(2017)
add_subdirectory(2018)
add_subdirectory(socket)
add_subdirectory(tlpi)
add_subdirectory(string)
add_subdirectory(pointer)
add_subdirectory(stdlib)
