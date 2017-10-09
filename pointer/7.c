//
// Created by zhangrongxiang on 2017/9/27 15:22
// File 7
//


#include <stdio.h>

int main() {
    int a = 10, *pInt;
    pInt = &a;
    printf("%d\n", pInt);
    printf("%d\n", *pInt);
}