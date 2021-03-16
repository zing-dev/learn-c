add_executable(cpfile cpfile.c ${LIB_CSAPP_SOURCES})
target_link_libraries(cpfile pthread)

add_executable(cpstdin cpstdin.c ${LIB_CSAPP_SOURCES})
target_link_libraries(cpstdin pthread)

add_executable(ex10-1 ex10-1.c ${LIB_CSAPP_SOURCES})
target_link_libraries(ex10-1 pthread)

add_executable(ex10-2 ex10-2.c ${LIB_CSAPP_SOURCES})
target_link_libraries(ex10-2 pthread)

add_executable(ex10-3 ex10-3.c ${LIB_CSAPP_SOURCES})
target_link_libraries(ex10-3 pthread)



