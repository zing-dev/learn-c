add_executable(csapp-common-error error.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-error pthread)

add_executable(csapp-common-process process.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-process pthread)

