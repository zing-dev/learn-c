//
// Created by zhangrongxiang on 2017/9/21 16:50
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    pid = fork(); // 创建进程
    if (pid < 0) { // 出错
        perror("fork");
        exit(0);
    }

    if (pid == 0) {// 子进程
        int i = 0;
        for (i = 0; i < 5; i++) {
            printf("this is son process\n");
            sleep(1);
        }

        _exit(2); // 子进程退出，数字 2 为子进程退出的状态

    } else if (pid > 0) { // 父进程

        int status = 0;

        // 等待子进程结束，回收子进程的资源
        // 此函数会阻塞
        // status 某个字段保存子进程调用 _exit(2) 的 2，需要用宏定义取出
        wait(&status);
        // waitpid(-1, &status, 0); // 和 wait() 没区别，0：阻塞
        // waitpid(pid, &status, 0); // 指定等待进程号为 pid 的子进程， 0 阻塞
        // waitpid(pid, &status, WNOHANG); // WNOHANG：不阻塞
        if (WIFEXITED(status) != 0) { // 子进程是否正常终止
            printf("son process return %d\n", WEXITSTATUS(status));
        }

        printf("this is father process\n");
    }

    return 0;
}