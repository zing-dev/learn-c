//
// Created by zhangrongxiang on 2017/8/22 9:42.
// Copyright (c) 2017 ZRX . All rights reserved.
//
#include<stdio.h>
#define PRINT_DBG(debug, ...)\
{\
    if(debug) {\
        printf("-------------------------begin--------------------------\n");\
        fprintf(stderr, "%s %s [%d]: ", __FILE__, __FUNCTION__, __LINE__);\
        fprintf(stderr, __VA_ARGS__);\
        printf("-------------------------end--------------------------\n");\
    }\
    else{\
        printf("else...................\n");\
    }\
}
#define MACRO(s, ...) printf(s, ##__VA_ARGS__)
int main()
{
    int i = 100;
    PRINT_DBG(1, "hello\n");
    PRINT_DBG(1, "world, %d\n", i);
    MACRO("hello, world\n"); //这里没有可变参数， 所以要用##__VA_ARGS__
    MACRO("hello, %s\n%s\n", "zhangrongxiang","WTF");
    return 0;
}
