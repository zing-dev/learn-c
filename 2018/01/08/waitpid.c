//
// Created by zhangrongxiang on 2018/1/8 13:50
// File waitpid
//

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main() {
    pid_t pc, pr;

    pc = fork();
    if (pc < 0)  /* 如果fork出错 */
        printf("Error occured on forking.\n");
    else if (pc == 0) {  /* 如果是子进程 */
        sleep(4); /* 睡眠4秒 */
        exit(0);
    }
    /* 如果是父进程 */
    do {
        /**
         * pid_t waitpid(pid_t pid, int *status, int options);
         *
         * < -1   meaning wait for any child process whose process group ID  is  equal to the absolute value of pid.
         * -1     meaning wait for any child process.
         * 0      meaning  wait  for any child process whose process group ID is equal to that of the calling process.
         * > 0    meaning wait for the child whose process ID is equal to the value of pid.
         */
        pr = waitpid(pc, NULL, WNOHANG); /* 使用了WNOHANG参数，waitpid不会在这里等待 */
        if (pr == 0) {   /* 如果没有收集到子进程 */
            printf("No child exited\n");
            sleep(1);
        }
    } while (pr == 0);    /* 没有收集到子进程，就回去继续尝试 */
    if (pr == pc)
        printf("successfully release child %d\n", pr);
    else
        printf("some error occured\n");
}