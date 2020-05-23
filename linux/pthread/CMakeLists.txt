set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wall")
set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE)

add_executable(pthread-demo demo.c)
target_link_libraries(pthread-demo pthread)

add_executable(pthread_create pthread_create.c)
target_link_libraries(pthread_create pthread)
