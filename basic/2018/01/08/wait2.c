//
// Created by zhangrongxiang on 2018/1/8 13:46
// File wait2
//

/* wait2.c */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main() {
    int status;
    pid_t pc, pr;
    pc = fork();
    if (pc < 0) /* 如果出错 */
        printf("error ocurred!\n");
    else if (pc == 0) { /* 子进程 */
        printf("This is child process with pid of %d.\n", getpid());
        exit(3); /* 子进程返回3 */
    } else {  /* 父进程 */
        pr = wait(&status);
        if (WIFEXITED(status)) { /* 如果WIFEXITED返回非零值 */
            printf("the child process %d exit normally.\n", pr);
            printf("the return code is %d.\n", WEXITSTATUS(status));
        } else   /* 如果WIFEXITED返回零 */
            printf("the child process %d exit abnormally.\n", pr);
    }
}
