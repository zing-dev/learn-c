//
// Created by 张荣响 on 2017/8/9.
//


#include <stdio.h>
#include <strings.h>


//置字节字符串前n个字节为零且包括‘\0’。

int main() {
    char str[10] = {'a', 'b', 'c', 'd'};

    printf("%s\n", str);
    bzero(&str, 4);
    printf("%s\n", str);

    memset(&str, '*', sizeof(str) - 1);
    printf("%s\n", str);
    bzero(&str, sizeof(str));
    printf("%s\n", str);
    printf("------------------------\n");
}