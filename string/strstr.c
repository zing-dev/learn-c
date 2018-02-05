//
// Created by zhangrongxiang on 2017/8/15 14:15.
// Copyright (c) 2017 ZRC . All rights reserved.
//

//#include <syslib.h>
#include <string.h>
#include <stdio.h>

//C 库函数 char *strstr(const char *haystack, const char *needle) 在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。

void find_str(char const *str, char const *substr) {
    char *pos = strstr(str, substr);
    if (pos) {
        printf("found the string '%s' in '%s' at position: %ld; result: %s\n", substr, str, pos - str,pos);
    } else {
        printf("the string '%s' was not found in '%s'\n", substr, str);
    }
}

int main() {
    char *s = "GoldenGlobalView";
    char *l = "lob";
    char *p;
    //返回值：若str2是str1的子串，则返回str2在str1的首次出现的地址；
    // 如果str2不是str1的子串，则返回NULL。
    p = strstr(s, l);
    if (p)
        //lobalView
        printf("%s\n", p);
    else
        printf("NotFound!\n");

    char *str = "one two three";
    find_str(str, "two");
    find_str(str, "");
    find_str(str, "nine");
    find_str(str, "n");

    return 0;
}