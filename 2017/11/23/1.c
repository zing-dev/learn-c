//
// Created by zhangrongxiang on 2017/11/23 16:57
// File 1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str[30] = {NULL};
    char str2[30][26] = {0};
    int i, j;
    for (i = 0; i < 20; ++i) {
        char *buf = (char *) malloc(sizeof(char) * 10);
        *buf = i + 97;
        str[i] = buf;
//        memcpy(str2[i], "hhh", strlen("hhh"));
//        strcpy(str2[i], "hhh");
//        free(buf);
    }

    for (j = 0; j < 30; ++j) {
        printf("%d  --> %s \n", j, str[j]);
        printf("%d  --> %s \n", j, str2[j]);
    }
}