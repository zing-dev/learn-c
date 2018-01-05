//
// Created by zhangrongxiang on 2018/1/5 9:36
// File 1
//


#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main() {
    pid_t pc, pr;
    pc = fork();
    if (pc < 0)        /* 如果出错 */
        printf("error ocurred!\n");
    else if (pc == 0) {        /* 如果是子进程 */
        printf("This is child process with pid of %d\n", getpid());
        sleep(10);    /* 睡眠10秒钟 */
    } else {            /* 如果是父进程 */
        pr = wait(NULL);    /* 在这里等待 */
        printf("I catched a child process with pid of %d\n", pr);
    }
    exit(0);
}