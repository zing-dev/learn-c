//
// Created by zhangrongxiang on 2017/8/17 14:53.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include<stdio.h>

void fun(int (*p)(int *, int *), int *pa, int *pb);

int sum(int *, int *);

int max(int *, int *);

int min(int *, int *);

int main(void) {
    int a, b, choice, *pa, *pb;

    printf("Enter two number and choose what do you want to do.\n");
    printf("Please enter a:");
    scanf("%d", &a);
    pa = &a;
    printf("Please enter b:");
    scanf("%d", &b);
    pb = &b;
    printf("What do you want to do?\n");
    printf("1.Add two number.\n2.Return the max.\n3.Return the min.\n");
    scanf("%d", &choice);

    if (choice == 1)
        fun(sum, pa, pb);
    else if (choice == 2)
        fun(max, pa, pb);
    else if (choice == 3)
        fun(min, pa, pb);

    return 0;
}

void fun(int (*p)(int *, int *), int *pa, int *pb) {
    int result;
    result = (*p)(pa, pb);
    printf("The result is:%d\n", result);
}

int sum(int *pa, int *pb) {
    return *pa + *pb;
}

int max(int *pa, int *pb) {
    if (*pa >= *pb)
        return *pa;
    else
        return *pb;
}

int min(int *pa, int *pb) {
    if (*pa <= *pb)
        return *pa;
    else
        return *pb;
}