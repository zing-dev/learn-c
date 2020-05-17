//
// Created by zhangrongxiang on 2017/10/31 15:14
// File pipe3
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

void handler(int sig) {
    printf("recv sig=%d\n", sig);
}

int main(int argc, char *argv[]) {
    signal(SIGPIPE, handler);

    int pipefd[2];
    if (pipe(pipefd) == -1)
        ERR_EXIT("pipe error");

    pid_t pid;
    pid = fork();
    if (pid == -1)
        ERR_EXIT("fork error");

    if (pid == 0) {
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
    close(pipefd[0]);
    sleep(1);
    int ret = write(pipefd[1], "hello", 5);
    if (ret == -1) {
        printf("err=%s\n", strerror(errno));
    }
//    recv sig=13
//    err=Broken pipe

    return 0;
}