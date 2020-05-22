//
// Created by zing on 5/22/2020.
//

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/user.h>

int main(int argc, char *argv[]) {
    printf("_SC_PAGESIZE %ld\n",sysconf(_SC_PAGESIZE)); //4096
    printf("PAGE_SIZE %lu\n",PAGE_SIZE); //4096

    printf("_SC_ARG_MAX %ld\n",sysconf(_SC_ARG_MAX)); //2097152

    printf("_SC_OPEN_MAX %ld\n",sysconf(_SC_OPEN_MAX)); //1024

    printf("_SC_STREAM_MAX %ld\n",sysconf(_SC_STREAM_MAX)); //16

    printf("HOST_NAME_MAX %d\n",HOST_NAME_MAX); //64
    printf("_SC_HOST_NAME_MAX %ld\n",sysconf(_SC_HOST_NAME_MAX)); //64
    return 0;
}
