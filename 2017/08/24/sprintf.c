//
// Created by zhangrongxiang on 2017/8/24 14:27.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(0));
    char s[64];
    int offset = 0;
    for (int i = 0; i < 10; i++) {
        offset += sprintf(s + offset, "%d,", rand() % 100);
    }
    s[offset - 1] = '\n';//将最后一个逗号换成换行符。
//    6,27,66,27,0,15,56,0,52,70
    printf(s);

    char str[20];
//    char s[20];
    char s1[3] = {'A', 'B', 'C'};
    char s2[3] = {'T', 'Y', 'x'};
    sprintf(str, "%.*s%.*s", 2, s1, 3, s2);
    sprintf(s, "%*.*f", 10, 2, 3.1415926);

//    ABTYx
    printf(str);
    return 0;
}