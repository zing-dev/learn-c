set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wall")

add_executable(pthread-demo demo.c)
target_link_libraries(pthread-demo pthread)