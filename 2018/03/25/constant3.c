//
// Created by zhangrongxiang on 2018/3/25 21:38
// File constant3
//
#include <stdio.h>
int main() {
    const int a;
    int const a2;
    int *pi = (int *) &a;
    *pi = 19;
    printf("%d\n", a);//19
    pi = (int *) &a2;
    *pi = 20;
    printf("%d\n", a2);//20
    return 0;
}