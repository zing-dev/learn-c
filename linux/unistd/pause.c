//
// Created by zing on 5/18/2020.
//

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void my_alarm(){
    printf("收到SIGALRM信号\n");
}

int main(){
    signal(SIGALRM,my_alarm);
    alarm(5);
    printf("开始暂停,5秒之后结束\n");
    pause();
    printf("结束暂停\n");
    return 0;
}

