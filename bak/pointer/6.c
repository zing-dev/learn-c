//
// Created by zhangrongxiang on 2017/8/17 15:02.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include<stdio.h>

int *max(int *, int *);

//·指针函数即返回值为指针的函数；

int main(void) {
    int a, b;
    int *pa, *pb, *pmax;
    int *(*p)(int *, int *);
    printf("Please input a:\n");
    scanf("%d", &a);
    pa = &a;
    printf("Please input b:\n");
    scanf("%d", &b);
    pb = &b;

    p = max;  //let p point to max funtion.
    pmax = (*p)(pa, pb); //call the funtion through pointer p.
//  pmax = max(pa, pb);
    printf("The max number is:%d\n", *pmax);
    return 0;
}

int *max(int *pa, int *pb) {
    if (*pa >= *pb)
        return pa;
    else
        return pb;
}