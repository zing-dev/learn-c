//
// Created by zhangrongxiang on 2018/3/15 15:27
// File 5
//

#include <stdio.h>

int main() {
    char str[] = "Hello World";
    const char *pStr = "Hello";
    printf("%s\n", str);
    printf("%c\n", str[0]);
    printf("%c\n", str[1]);
    printf("----------------------------------------------\n");
    printf("%s\n", str);//Hello World
    printf("%c\n", (*str));//H
    printf("%c\n", ++(*str));//I
    printf("%s\n", str);//Iello World
    printf("%c\n", --(*str));//H
    printf("%s\n", str);//Hello World

    printf("----------------------------------------------\n");
    printf("%c\n", *(str + 1));//e
    printf("%c\n", *(str + 2));//l

    printf("----------------------------------------------\n");
    char *src = str;
    printf("%s\n", str);//Hello World
    printf("%c\n", *src++);//H
    printf("%c\n", *src);//e
    return 0;
}