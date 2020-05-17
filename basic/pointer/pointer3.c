//
// Created by zhangrongxiang on 2018/2/24 16:43
// File pointer3
//

#include <stdio.h>
#include <string.h>

int main() {
    char *str = "hello world";
    char *str2 = "hello c";
    char *arr[20] = {str, str2};
    char **arr2 = arr;
    printf("%s\n", str);//hello world
    char **pStr = &str;
    char ***ppStr = &pStr;
    printf("%s\n", *pStr);//hello world
    printf("%s\n", pStr[0]);//hello world
    printf("%s-%s\n", arr[0], arr[1]);//hello world-hello c
    printf("%s-%s\n", arr2[0], arr2[1]);//hello world-hello c
    return 0;
}