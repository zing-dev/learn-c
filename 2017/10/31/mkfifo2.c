//
// Created by zhangrongxiang on 2017/10/31 15:05
// File mkfifo2
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

    int outfd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfd == -1)
        ERR_EXIT("open error");

    int infd;
    infd = open("mkfifo2.c", O_RDONLY);
    if (infd == -1)
        ERR_EXIT("open error");

    char buf[1024];
    int n;
    while ((n = read(infd, buf, 1024)) > 0)
        write(outfd, buf, n);

    close(infd);
    close(outfd);
//    unlink("out.txt"); // delete a name and possibly the file it refers to
    return 0;
}