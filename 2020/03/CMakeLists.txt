cmake_minimum_required(VERSION 3.2)

project(03)
add_subdirectory(26)
aux_source_directory(./26 DIR_SRCS)
add_executable(03 ${DIR_SRCS})
