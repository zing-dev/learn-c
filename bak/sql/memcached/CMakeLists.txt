cmake_minimum_required(VERSION 3.7.2)
project(memcached)
add_executable(
        memcached
        main.c
        init.c mem.c mem2.c)