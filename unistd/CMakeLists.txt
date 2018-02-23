cmake_minimum_required(VERSION 3.7.2)
project(unistd)

add_executable(unistd
        chown.c
        chown2.c chown3.c access.c alarm.c)
