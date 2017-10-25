//
// Created by zhangrongxiang on 2017/10/25 17:09
// File vsprintf
//

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char buffer[80];

int vspf(char *fmt, ...) {
    va_list argptr;
    int cnt;
    va_start(argptr, fmt);

//    vsprintf 用于执行有不定数量参数的函数，类似printf 格式
//    int vsprintf(char *string, char *format, va_list param);
    cnt = vsprintf(buffer, fmt, argptr);
    va_end(argptr);
    return (cnt);
}

int main(void) {
    int inumber = 30;
    float fnumber = 90.0;
    char string[4] = "abc";
    vspf("%d %f %s", inumber, fnumber, string);
//    30 90.000000 abc
    printf("%s\n", buffer);
    return 0;
}