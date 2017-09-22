//
// Created by zhangrongxiang on 2017/9/22 10:35
//

#include <stdio.h>
#include <stdlib.h>

int fun1(void) {
    printf("hello world.\n");
    return 0;
}

int fun2(int i) {
    printf("参数是 %d\n", i);
    return i;
}

int *fun3() {
    printf("fun3.....\n");
}

void callback(int (*pfun)()) {
    pfun();
}

void callback2(int (*pfun)(int a), int a) {
    pfun(a);
}

int main(void) {
    callback(fun1);
    callback2(fun2, 2);
    int (*f)(int);
    f = fun2;
    f(2);
}