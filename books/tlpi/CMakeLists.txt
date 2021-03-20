cmake_minimum_required(VERSION 3.7.2)
project(tlpi)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}})
add_executable(copy copy.c tlpi_hdr.h error_functions.h error_functions.c)

add_executable(simple_thread simple_thread.c tlpi_hdr.h error_functions.c error_functions.h)
target_link_libraries(simple_thread pthread)

add_executable(prod_no_condvar.c prod_no_condvar.c tlpi_hdr.h error_functions.c error_functions.h)
target_link_libraries(prod_no_condvar.c pthread)