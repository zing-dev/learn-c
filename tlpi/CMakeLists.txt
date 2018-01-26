cmake_minimum_required(VERSION 3.7.2)
project(tlpi)

set(CMAKE_CXX_STANDARD 11)

add_executable(tlpi
        error_functions.c error_functions.h get_num.h get_num.c
#        simple_thread.c
#        detached_attrib.c
#        thread_incr.c
#        thread_incr_mutex.c
        prod_no_condvar.c

        )

