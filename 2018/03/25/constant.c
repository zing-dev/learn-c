//
// Created by zhangrongxiang on 2018/3/25 21:08
// File constant
//

#include <stdio.h>

int main() {
    printf("--------------------Hello World---------------------\n");
    char *str = "hi";
    char *str2 = "hi";
    printf("=> %d\n", str == str2);//1
    char str3[] = "hi";
    char str4[] = "hi";
    printf("=> %d\n", str3 == str4);//0

    char const *str5 = "hi";
    char const *str6 = "hi";
    printf("=> %d\n", str5 == str6);//1

    char *const str7 = "hi";
    char *const str8 = "hi";
    printf("=> %d\n", str5 == str6);//1

    char const str9[] = "hi";
    char const str10[] = "hi";
    printf("=> %d\n", str9 == str10);//0
}