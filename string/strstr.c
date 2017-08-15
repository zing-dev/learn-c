//
// Created by zhangrongxiang on 2017/8/15 14:15.
// Copyright (c) 2017 ZRC . All rights reserved.
//

//#include <syslib.h>
#include <string.h>
#include <stdio.h>
int main()
{
    char *s = "GoldenGlobalView";
    char *l = "lob";
    char *p;
    //返回值：若str2是str1的子串，则返回str2在str1的首次出现的地址；
    // 如果str2不是str1的子串，则返回NULL。
    p = strstr(s, l);
    if (p)
        //lobalView
        printf("%s", p);
    else
        printf("NotFound!");
    return 0;
}