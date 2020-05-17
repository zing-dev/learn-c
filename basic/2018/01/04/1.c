//
// Created by zhangrongxiang on 2018/1/4 11:03
// File 1
//
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main() {
    pid_t pid;
    char *pchar = "before fork";
    int test_va = 1;

    if ((pid = fork()) < 0) {
        printf("fork error!!\n");
        exit(1);
    } else if (pid == 0) {
        printf("child process\n");
        pchar = "child pchr\n";
        printf("%s\n", pchar);
        printf("---  child process --> %d\n", test_va);
        test_va = 2;
        printf("child process --> %d\n", test_va);
        _exit(2);
    } else {
        printf("parent process\n");
        printf("%s\n", pchar);
        printf("parent process --> %d\n", test_va);
    }
}