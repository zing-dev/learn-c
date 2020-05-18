//
// Created by zing on 5/18/2020.
//

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void gio(){
    printf("接收到 SI_SIGIO 信号\n");
}

int main(){
    printf("注册 SI_SIGIO 信号\n");
    signal(SI_SIGIO,gio);
    sleep(5);
    raise(SI_SIGIO);
    sleep(1);
    raise(SIGKILL);
    sleep(1);
    return 0;
}