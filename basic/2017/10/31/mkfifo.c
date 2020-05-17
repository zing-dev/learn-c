//
// Created by zhangrongxiang on 2017/10/31 15:02
// File mkfifo
//

#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<signal.h>

#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

int main(int argc, char *argv[]) {
    unlink("test");

//  int mkfifo(const char *filename,mode_t mode);
    mkfifo("test", 0644);
    int infd = open("mkfifo.c", O_RDONLY);
    if (infd == -1)
        ERR_EXIT("open error");

    int outfd;
    outfd = open("test.txt", O_WRONLY);
    if (outfd == -1)
        ERR_EXIT("open error");

    char buf[1024];
    int n;
    while ((n = read(infd, buf, 1024)) > 0)
        write(outfd, buf, n);
    unlink("test");
    close(infd);
    close(outfd);
    return 0;
}