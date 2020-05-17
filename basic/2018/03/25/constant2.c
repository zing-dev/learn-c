//
// Created by zhangrongxiang on 2018/3/25 21:16
// File constant2
//

#include <stdio.h>

int main() {
    const char c = 'a';
//    c = 'b';
    char const c2 = 'a';
//    c = 'b';

    char *const str = "hello";
//    str++;
//    (*str)++;
    printf("%s\n", str);

    char const *str2 = "hello";
    str2++;
    printf("%s\n", str2);//ello
    const char *str3 = "hello";
    str3++;
    printf("%s\n", str3);//ello
//    (*str3)++;
    return 0;
}