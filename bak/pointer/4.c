//
// Created by zhangrongxiang on 2017/8/17 14:46.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include<stdio.h>

int max(int *, int *);

int main(void) {
    int a, b, max_num;
    int *pa, *pb;
    int (*p)(int *, int *);
    printf("Please input a:\n");
    scanf("%d", &a);
    pa = &a;
    printf("Please input b:\n");
    scanf("%d", &b);
    pb = &b;

    p = max;  //let p point to max funtion.
    max_num = (*p)(pa, pb); //call the funtion through pointer p.
//  max_num = max(pa, pb);
    printf("The max number is:%d\n", max_num);
    return 0;
}

int max(int *pa, int *pb) {
    if (*pa >= *pb)
        return *pa;
    else
        return *pb;
}