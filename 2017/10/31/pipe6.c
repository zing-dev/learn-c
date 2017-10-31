//
// Created by zhangrongxiang on 2017/10/31 15:27
// File pipe6
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
//进程间通信（IPC，InterProcess Communication）
#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

int main(int argc, char *argv[]) {
//    0是标准输入(read)   1是标准输出(write)
    int pipefd[2];
//    父进程调用pipe开辟管道，得到两个文件描述符指向管道的两端。
    if (pipe(pipefd) == -1)
        ERR_EXIT("pipe error");

    pid_t pid;
//    父进程调用fork创建子进程，那么子进程也有两个文件描述符指向同一管道。
    pid = fork();
    if (pid == -1)
        ERR_EXIT("fork error");

// 父进程关闭管道写端，子进程关闭管道读端。
// 子进程可以往管道里写，父进程可以从管道里读，管道是用环形队列实现的，
// 数据从写端流入从读端流出，这样就实现了进程间通信。
    if (pid == 0) {
        close(pipefd[0]);
        write(pipefd[1], "hello", 5);
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }

    close(pipefd[1]);
    char buf[10] = {0};
    read(pipefd[0], buf, 10);
    printf("buf=%s\n", buf);
    close(pipefd[0]);
    return 0;
}

