//
// Created by zhangrongxiang on 2018/1/3 14:56
// File 2
//
#include <stdio.h>

int main(int argc, char **argv) {
    int i = 0;
    for (i = 0; i < argc; ++i) {
        printf("%d  -->  %s \n", i, argv[i]);
    }
}