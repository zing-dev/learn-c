//
// Created by zhangrongxiang on 2018/2/22 10:41
// File argv
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc --> %d\n", argc);
    int i = 0;
    for (; i < argc; i++) {
        printf("%d --> %s || %c\n", i, argv[i], argv[i][0]);
    }
    return 0;
}