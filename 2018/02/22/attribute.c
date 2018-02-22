//
// Created by zhangrongxiang on 2018/2/22 13:41
// File attribute
//

#include <stdio.h>

static  __attribute__((constructor)) void before() {

    printf("Hello\n");
}

static  __attribute__((destructor)) void after() {
    printf(" World!\n");
}

struct foo {
    int x[2] __attribute__ ((aligned (8)));
};

int main() {
    int x __attribute__ ((aligned (16))) = 0;
    int x2 __attribute__ ((aligned (32))) = 0;
    printf("%d\n", (int) sizeof(x));//4
    printf("%d\n", (int) sizeof(x2));//4
    printf("%d\n", (int) sizeof(struct foo));//8
    typedef struct foo foo;
    foo f;
    printf("%d\n", (int) sizeof(foo));//8
    printf("%d\n", (int) sizeof(f.x));//8
    return 0;
}