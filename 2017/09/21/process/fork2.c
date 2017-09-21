//
// Created by zhangrongxiang on 2017/9/21 15:52
//


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int a = 10;     // 全局变量
int main(int argc, char *argv[]) {
    pid_t pid;
    pid = fork();
    int b = 20; //局部变量

    if (pid < 0) {    // 没有创建成功
        perror("fork");
    }

    if (0 == pid) { // 子进程
        a = 111;
        b = 222;    // 子进程修改其值
        printf("son: a = %d, b = %d\n", a, b);
    } else if (pid > 0) { // 父进程
        sleep(2);   // 保证子进程先运行,但不保证1秒足够
        printf("father: a = %d, b = %d\n", a, b);
    }

    return 0;
}