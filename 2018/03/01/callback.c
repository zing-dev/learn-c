//
// Created by zhangrongxiang on 2018/3/1 14:14
// File callback
//

#include <stdio.h>

int add(int a, int b);

    int add(int a, int b) {
    return a + b;
}

int test(int a, int b, int (*sum)(int, int)) {
    return (*sum)(a, b);
}

int main() {
    int s = test(2, 3, add);
    printf("sum is %d\n", s);
}