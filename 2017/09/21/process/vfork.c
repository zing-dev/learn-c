//
// Created by zhangrongxiang on 2017/9/21 15:59
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int a = 10;

int main(int argc, char *argv[]) {
    pid_t pid;
    int b = 20;
    /*
     * 1）fork()： 父子进程的执行次序不确定。
        vfork()：保证子进程先运行,在它调用 exec（进程替换） 或 exit（退出进程）之后父进程才可能被调度运行。
        2）fork()： 子进程拷贝父进程的地址空间，子进程是父进程的一个复制品。
        vfork()：子进程共享父进程的地址空间（准确来说，在调用 exec（进程替换） 或 exit（退出进程） 之前与父进程数据是共享的）
     */
    pid = vfork();    // 创建进程
    if (pid < 0) { // 出错
        perror("vfork");
    }

    if (0 == pid) { // 子进程
        sleep(1); // 延时 3 秒
        printf("i am son\n");
        printf("son a = %d, b = %d \n", a, b);
        _exit(0); // 退出子进程，必须
    } else if (pid > 0) { // 父进程
        printf("f a = %d, b = %d \n", a, b);
        printf("i am father\n");
    }

    return 0;
}