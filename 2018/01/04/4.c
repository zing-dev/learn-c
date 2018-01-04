//
// Created by zhangrongxiang on 2018/1/4 14:23
// File 4
//

#include <unistd.h>
#include <stdio.h>

int main(void) {
    int i = 0;
    printf("i son/pa ppid pid  fpid\n");
    //ppid指当前进程的父进程pid
    //pid指当前进程的pid,
    //fpid指fork返回给当前进程的值
    for (i = 0; i < 2; i++) {
        pid_t fpid = fork();
        if (fpid == 0)
            printf("i -> %d  child  getppid -> %6d  getpid -> %6d fpid -> %6d\n", i, getppid(), getpid(), fpid);
        else
            printf("i -> %d parent  getppid -> %6d  getpid -> %6d fpid -> %6d\n", i, getppid(), getpid(), fpid);
    }
    return 0;
}