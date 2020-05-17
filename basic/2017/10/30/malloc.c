//
// Created by zhangrongxiang on 2017/10/30 10:29
// File malloc
//

#include<stdio.h>
#include<stdlib.h>

//#include<malloc.h>
int main() {
    char *p;
    p = (char *) malloc(10000);
    if (p) {
        printf("Memory Allocated at: %x\n", p);
        printf("%d\n", sizeof(p));

        printf("%d\n", sizeof(*p));
        printf("--->> %d\n", sizeof("1234567890"));
        printf("malloc --->> %d\n", sizeof(malloc(1000 * sizeof(long double))));
        printf("-------- > %d\n", sizeof(p) / sizeof(p[0]));
        printf("%d\n", sizeof(char));
        printf("%d\n", sizeof(int));
        printf("%d\n", sizeof(long double));
    } else
        printf("Not Enough Memory!\n");
    free(p);
    return 0;
}