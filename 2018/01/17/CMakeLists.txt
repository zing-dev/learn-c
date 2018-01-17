cmake_minimum_required(VERSION 3.0)
project(json)
add_executable(main.out main.c)
add_subdirectory(parson)
# 添加链接库
target_link_libraries(main.out json)