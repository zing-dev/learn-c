//
// Created by zhangrongxiang on 2017/9/22 17:24
//

#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void fun(void) {
    printf("in fun()\n");
    longjmp(buf, 1);
}

void main(void) {
    if (setjmp(buf)) {
        printf("back in main.\n");
    } else {
        printf("first time through\n");
        fun();
    }

    printf("---------------------over----------------------\n");
}