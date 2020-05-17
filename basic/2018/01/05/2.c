//
// Created by zhangrongxiang on 2018/1/5 9:48
// File 2
//

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
main() {
    int status;
    pid_t pc, pr;
    pc = fork();
    if (pc < 0) /* 如果出错 */
        printf("error ocurred!\n");
    else if (pc == 0) { /* 子进程 */
        printf("This is child process with pid of %d.\n", getpid());
        exit(3);    /* 子进程返回3 */
    } else {       /* 父进程 */
        pr = wait(&status);
        //WIFEXITED(status) 这个宏用来指出子进程是否为正常退出的，如果是，它会返回一个非零值。
        if (WIFEXITED(status)) {  /* 如果WIFEXITED返回非零值 */
            printf("the child process %d exit normally.\n", pr);
            printf("the return code is %d.\n", WEXITSTATUS(status));
        } else           /* 如果WIFEXITED返回零 */
            printf("the child process %d exit abnormally.\n", pr);
    }
}