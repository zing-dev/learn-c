//
// Created by zhangrongxiang on 2017/9/21 15:08
//

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    /**
     *  进程：进程可以理解为程序执行的一个实例
     *  进程描述符:类型为task_struct的结构体
     *  进程状态：进程描述符task_struct结构体中有一个state字段，表示进程当前的所处状态。
     *  进程标示符：进程描述task_struct结构体中的pid字段可以标识唯一标识一个进程，称之为进程标识符PID。
     */
    if (0 == fork()) {
        printf("\nchild process\n");
        printf("child getpid() id %d\n", getpid());
        printf("child getppid() id %d\n", getppid());
        printf("child getpgid() id %d\n", getpgid(getpid()));
    }
    printf("\ncurrent process\n");
    printf("getpid() id %d\n", getpid());
    printf("getppid() id %d\n", getppid());
    printf("getpgid() id %d\n", getpgid(getpid()));


    fork();
    printf("------->>>>>>>>  getpid() id %d\n", getpid());

    return 0;
}