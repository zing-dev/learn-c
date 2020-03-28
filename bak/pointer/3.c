//
// Created by zhangrongxiang on 2017/8/17 12:09.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdio.h>

int main(void) {
    char str[] = "zhangrongxiang";
    char *p = str;
    printf("str   = %p        p        = %p\n", str, p);
    printf("str+1 = %p        &str + 1 = %p\n", str + 1, &str + 1);
    printf("p+1   = %p\n", p + 1);
    return 0;
}