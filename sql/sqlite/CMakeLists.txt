cmake_minimum_required(VERSION 3.7.2)
project(sqlite)
add_executable(
        sqlite
        1.c
        2.c
        3.c
        log.c log.h
        main.c
        sqlite3.h
        sqlite3ext.h
        sql.c sqlite.c)