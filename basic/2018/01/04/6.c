//
// Created by zhangrongxiang on 2018/1/4 14:48
// File 6
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *str[] = {"hello", "world", "you", "are", "SB"};

int main() {
    int i = 0;
    pid_t fp[5];
    for (; i < 5; ++i) {
        fp[i] = fork();
        if (fp[i] == 0) {
            printf("[%d] pid==0    ==>  %s\n", i, str[i]);
            exit(0);
        } else if (fp[i] > 0) {
            printf("pid > 0\n");
        } else {
            printf("error\n");
        }
    }
    return 0;
}