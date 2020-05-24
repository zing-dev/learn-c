set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wall")
set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE)

add_executable(pthread-demo demo.c)
target_link_libraries(pthread-demo pthread)

add_executable(pthread_create pthread_create.c)
target_link_libraries(pthread_create pthread)

add_executable(pthread_exit pthread_exit.c)
target_link_libraries(pthread_exit pthread)

add_executable(pthread_join pthread_join.c)
target_link_libraries(pthread_join pthread)

add_executable(pthread_attr_init pthread_attr_init.c)
target_link_libraries(pthread_attr_init pthread)

add_executable(pthread_attr_init2 pthread_attr_init2.c)
target_link_libraries(pthread_attr_init2 pthread)