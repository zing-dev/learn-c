//
// Created by zhangrongxiang on 2018/2/5 17:28
// File strspn
//

#include <stdio.h>
#include <string.h>

//C 库函数 size_t strspn(const char *str1, const char *str2) 检索字符串 str1 中第一个不在字符串 str2 中出现的字符下标。

int main() {
    size_t len;
    const char str1[] = "ABCDEFG02018ABCDEFG02018";
    const char str2[] = "ABCD";
    const char str3[] = "2018";
    const char str4[] = "AB";
    len = strspn(str1, str2);
    printf("%d\n", (unsigned int) len); //4
    len = strspn(str1, str3);
    printf("%d\n", (unsigned int) len); //0
    len = strspn(str1, str4);
    printf("%d\n", (unsigned int) len); //2
    return (0);
}