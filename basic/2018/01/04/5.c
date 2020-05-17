//
// Created by zhangrongxiang on 2018/1/4 14:38
// File 5
//

#include <stdio.h>
#include <unistd.h>

int i;
//20
int main(int argc, char *argv[]) {
    fork();
    fork() && fork() || fork();
    fork();
    printf("%d\n", i++);
    return 0;
}