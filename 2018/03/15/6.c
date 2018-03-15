//
// Created by zhangrongxiang on 2018/3/15 15:45
// File 6
//

#include <stdio.h>

int main() {
    char str[30] = {0};
    char *strDest = str;
    const char *strSrc = "Hello";
    char *address = strDest;                        // 2分
    while ((*strDest++ = *strSrc++) != '\0') {// 2分
        printf("%c - %s\n", *(strSrc - 1), address);
    }
    printf("--------------------------------------\n");
    printf("%s\n", address);
    printf("%s\n", strDest);
    printf("%s\n", str);
//    printf("%c\n",*strSrc++); // = printf("%c\n",*(strSrc++));
//    printf("%c\n",*strSrc++);
//    printf("%c\n",*strSrc++);
//    printf("%c\n",*strSrc);
    return 0;
}