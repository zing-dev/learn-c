cmake_minimum_required(VERSION 3.7.2)
project(stdlib)

add_executable(stdlib
        atof.c
        atoi.c atol.c strtod.c strtol.c div.c drand48.c ecvt.c system.c getenv.c)
