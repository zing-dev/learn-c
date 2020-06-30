add_executable(csapp-common-alarm alarm.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-alarm pthread)

add_executable(csapp-common-counterprob counterprob.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-counterprob pthread)

add_executable(csapp-common-fork fork.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-fork pthread)

add_executable(csapp-common-fork1 fork1.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-fork1 pthread)

add_executable(csapp-common-forkprob0 forkprob0.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob0 pthread)

add_executable(csapp-common-forkprob1 forkprob1.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob1 pthread)

add_executable(csapp-common-forkprob2 forkprob2.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob2 pthread)

add_executable(csapp-common-forkprob3 forkprob3.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob3 pthread)

add_executable(csapp-common-forkprob4 forkprob4.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob4 pthread)

add_executable(csapp-common-forkprob5 forkprob5.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob5 pthread)

add_executable(csapp-common-forkprob6 forkprob6.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob6 pthread)

add_executable(csapp-common-forkprob7 forkprob7.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob7 pthread)

add_executable(csapp-common-forkprob8 forkprob8.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-forkprob8 pthread)

add_executable(csapp-common-kill kill.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-kill pthread)

add_executable(csapp-common-procmask1 procmask1.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-procmask1 pthread)

add_executable(csapp-common-procmask2 procmask2.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-procmask2 pthread)

add_executable(csapp-common-restart restart.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-restart pthread)

add_executable(csapp-common-rfork rfork.c)
target_link_libraries(csapp-common-rfork pthread)

add_executable(csapp-common-setjmp setjmp.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-setjmp pthread)

add_executable(csapp-common-shellex shellex.c ${LIB_CSAPP_SOURCES})
target_link_libraries(csapp-common-shellex pthread)