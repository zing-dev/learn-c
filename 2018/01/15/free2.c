//
// Created by zhangrongxiang on 2018/1/15 16:40
// File free2
//

/* free example */
#include <stdlib.h>     /* malloc, calloc, realloc, free */
#include <stdio.h>
#include <string.h>
#include <zconf.h>


int main() {
    int *buffer1, *buffer2, *buffer3;
    buffer1 = (int *) malloc(100 * sizeof(int));
    buffer2 = (int *) calloc(100, sizeof(int));
    buffer3 = (int *) realloc(buffer2, 500 * sizeof(int));
    char *string = (char *) malloc(sizeof(char) * 100);
    memset(buffer1, 0, sizeof(int));
    char src[] = "Hello World";
//    memset(string, src, sizeof(src));
    memcpy(string, src, sizeof(src));
    free(buffer1);
    free(buffer3);
    free(string);
//    sleep(10);
    printf("%d\n", *buffer1);
    printf("%s\n", string);
    return 0;
}