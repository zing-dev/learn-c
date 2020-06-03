//
// Created by zhangrongxiang on 2017/8/15 14:15.
// Copyright (c) 2017 ZRC . All rights reserved.
//

#include <string.h>
#include <stdio.h>

//C 库函数 char *strstr(const char *haystack, const char *needle) 在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。

/* Find the first occurrence of NEEDLE in HAYSTACK.  */
void find_str(char const *str, char const *substr) {
    char *pos = strstr(str, substr);
    if (pos) {
        printf("found the string '%s' in '%s' at position: %ld; result: %s\n", substr, str, pos - str, pos);
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
    find_str(str, "two"); //found the string 'two' in 'one two three' at position: 4; result: two three
    find_str(str, ""); // found the string '' in 'one two three' at position: 0; result: one two three
    find_str(str, "nine");// the string 'nine' was not found in 'one two three'
    find_str(str, "n"); // found the string 'n' in 'one two three' at position: 1; result: ne two three

    char str2[] = "This is a simple string";
    char *pch;
    pch = strstr(str2, "simple");
    strncpy (pch, "sample", 6);
    puts(str2);//This is a sample string
    puts(pch);//sample string

    return 0;
}