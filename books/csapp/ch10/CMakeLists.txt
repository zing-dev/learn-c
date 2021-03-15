add_executable(cpfile cpfile.c ${LIB_CSAPP_SOURCES})
target_link_libraries(cpfile pthread)
