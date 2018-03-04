cmake_minimum_required(VERSION 3.7.2)
project(sqlite)
add_executable(
        sqlite
        1.c
        2.c
        3.c
        log.c log.h
        main.c
        sql.c
        sqlite.c)
