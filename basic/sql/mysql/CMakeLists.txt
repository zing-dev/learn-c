cmake_minimum_required(VERSION 3.7.2)
project(mysql)
add_executable(
        mysql
        mysql.c
        conn.c
        conn2.c
        database.c
        database.h
        select.c
        conn3.c main.c)