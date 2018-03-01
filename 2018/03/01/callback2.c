//
// Created by zhangrongxiang on 2018/3/1 14:30
// File callback2
//

#include <stdio.h>

int add_ret(int, int);

int add(int a, int b, int (*add_value)(int, int)) {
    return (*add_value)(a, b);
}

int main(void) {
    int sum = add(3, 4, add_ret);
    printf("sum:%d\n", sum);
    return 0;
}

int add_ret(int a, int b) {
    return a + b;
}