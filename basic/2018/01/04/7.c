//
// Created by zhangrongxiang on 2018/1/4 15:21
// File 7
//

#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"

int main() {
    pid_t pid1;
    pid_t pid2;

    pid1 = fork();
    pid2 = fork();

    printf("pid1:%6d, pid2:6%d\n", pid1, pid2);
}