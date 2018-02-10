//
// Created by 张荣响 on 2018/2/10.
//


#include <string.h>
#include <stdio.h>
int main() {
    char str[32] = "I am your GOD";
    char str2[32] = "Hello World";
    char str3[] = "void * memmove ( void * destination, const void * source, size_t num );";
    memmove(str2, str, strlen(str));
    printf("%s\n", str2);//I am your GOD
    memmove(str2, "hi\0hi", sizeof(str2));
    printf("%s\n", str2);//hi
    memmove(str, str3, sizeof(str) - 1);
    for (int i = 0; i < sizeof(str); ++i) {
        printf("%c", str[i]);
    }//void * memmove ( void * destina%
    return 0;
}