//
// Created by zing on 2021/3/25.
//
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("parent %d %d %d %d\n", getpid(), getppid(), getpgrp(), getpgid(0));
    for (int i = 0; i < 3; ++i) {
        if (fork() == 0){
            printf("child %d %d %d %d\n", getpid(), getppid(), getpgrp(), getpgid(0));
        }
    }
}