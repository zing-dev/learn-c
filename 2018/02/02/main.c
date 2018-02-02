//
// Created by zhangrongxiang on 2018/2/2 16:13
// File main
//
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "md5.h"

int main() {
    char *md = MDFile("./main.c");
    char *md2 = MDFile("./main.c");
    char md3[34];
    strcpy(md3, md2);
//    printf("%s\n",md);
    if (strncmp(md, md2, 33) == 0) {
        printf("equal\n");
    }

    if (strcmp(md, md2) == 0) {
        printf("equal\n");
    }
    if (strcmp(md3, md2) == 0) {
        printf("equal\n");
    }
    if (strncmp(md3, md2, sizeof(md3)) == 0) {
        printf("equal\n");
    }
    return EXIT_SUCCESS;
}