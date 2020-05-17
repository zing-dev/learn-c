//
// Created by zhangrongxiang on 2017/12/7 17:02
// File const
//


#include <stdio.h>

int main() {

//////////////////////////////////////////////////////////////////////////////////////////////////////////
    const int *a1;
    int const *a2;
//    这两种写法是一样的，a是一个指向const int型的指针，
//    a所指向的内存单元不可改写，所以(*a)++是不允许的，但a可以改写，所以a++是允许的。
    int b = 10;
    a1 = &b;
    printf("a1 ---> %8X\n", a1);
    printf("*a1 ---> %7X\n", *a1);
//    const.c:17:25: error: increment of read-only location ‘*a1’
//    printf("%8X\n",(*a1)++);
    printf("%8X\n", ++a1);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
    int c = 10;
    int *const a3 = &c;
//    a是一个指向int型的const指针，*a是可以改写的，但a不允许改写。
//    error: assignment of read-only variable ‘a3’
//    a3 = &c;
//    *a3 = c;
    printf("a3  ---> %8X\n", a3);
    printf("*a3 ---> %8X\n", *a3);
    printf("++(*a3) --> %5X\n", ++(*a3));

//////////////////////////////////////////////////////////////////////////////////////////////////////////
    int d = 10;
    int const *const a4 = &d;
//    a是一个指向const int型的const指针，因此*a和a都不允许改写。
    printf("a4  --> %8X\n", a4);
    printf("*a4  --> %7X\n", *a4);
    d = 11;
    printf("*a4  --> %7X\n", *a4);
    printf("a4  --> %8X\n", a4);

}