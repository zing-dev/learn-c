cmake_minimum_required(VERSION 3.7.2)
project(1)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(16/cmake)
add_subdirectory(17)
add_executable(
        1
        #        07/2.c
#        08/fork.c 08/clamscan.h 08/clamavtest.c 08/wait.c 08/wait2.c 08/waitpid.c 08/waitpid2.c 08/continue.c
#        09/clamavtest.c
#        09/pthread.c 09/clamavtest.h
#        11/uftp.c 11/server.c 11/client.c
#        11/struct.c
#        12/read.c 12/fread.c 12/fwrite_int.c 12/fread_int.c 12/fwrite_struct.c 12/fread_struct.c
#        15/free.c
#        15/free2.c
#        16/1.c 16/2.c
#        16/3.c 16/4.c 16/5.c 16/6.c 16/7.c 16/8.c 16/9.c
#        19/struct.c
#        19/static.c 19/extern.c 19/extern.h
#        22/1.c 22/2.c 22/mq/server.c 22/mq/client.c 22/mq/common.h 22/mq/attr.c 22/mq/open.c 22/mq/send.c 22/mq/receive.c 22/mq/notify.c 22/mq/server2.c
        23/continue.c)

