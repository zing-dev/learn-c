//
// Created by zhangrongxiang on 2018/1/19 15:33
// File static
//

#include <stdio.h>
#include "extern.h"

int i1;
char name[20];
int in = 100;

void testStatic() {
    static int i = 0;
    static int *pInt;
//    pInt = &in;
    pInt = &i;
    printf("i1 --> %d\n", i1);
    printf("%d --> %p\n", i++, pInt);
}

int main() {

    ex2();
    printf("%s\n", name);
    ex();
    testStatic();
    testStatic();
    testStatic();
    testStatic();
    testStatic();
    return 0;
}