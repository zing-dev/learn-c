//
// Created by zhangrongxiang on 2018/3/15 10:41
// File 1
//
#include <stdio.h>
int func(int x) {
    int countx = 0;
    while (x) {
        countx++;
        x = x & (x - 1);
    }
    return countx;
}

int main() {
    int i = func(10);
    printf("%d\n", i);
    i = func(10);
    printf("%d\n", i);
    return 0;
}