//
// Created by zhangrongxiang on 2018/2/23 9:41
// File alarm
//

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler();

int main() {
    int i;
    handler();
    for (i = 1; i < 21; i++) {
        printf("sleep %d ...\n", i);
        sleep(1);
    }
}

void handler() {
    printf("接收到SIGALRM信号\n");
    signal(SIGALRM, handler); //让内核做好准备，一旦接受到SIGALARM信号,就执行 handler
    alarm(5);
    printf("over\n");
}