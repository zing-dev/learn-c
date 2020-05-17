//
// Created by zhangrongxiang on 2017/10/31 15:15
// File pipe4
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
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }

    close(pipefd[1]);
    sleep(1);
    char buf[10] = {0};
    int ret = read(pipefd[0], buf, 10);
    printf("ret = %d\n", ret);
//    ret = 0

    return 0;
}