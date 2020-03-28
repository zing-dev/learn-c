cmake_minimum_required(VERSION 3.7.2)
project(redis)
add_executable(
        redis
        main.c
        string.c
        example.c
        hiredis
        string2.c)