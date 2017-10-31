//
// Created by zhangrongxiang on 2017/10/31 16:34
// File strstr
//

#include <stdio.h>
#include <string.h>

//C 库函数 char *strstr(const char *haystack, const char *needle)
// 在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。
int main() {
    const char haystack[20] = "W3CSchool11111";
    const char needle[10] = "School";
    char *ret;
//    char *strstr(const char *haystack, const char *needle)
    ret = strstr(haystack, needle);
///    子字符串是： School11111
    printf("子字符串是： %s\n", ret);
    return (0);
}