//
// Created by zhangrongxiang on 2018/3/15 11:18
// File 4
//

/*
编写strcpy函数（10分）
已知strcpy函数的原型是
    char *strcpy(char *strDest, const char *strSrc);
    其中strDest是目的字符串，strSrc是源字符串。
（1）不调用C++/C的字符串库函数，请编写函数 strcpy
（2）strcpy能把strSrc的内容复制到strDest，为什么还要char * 类型的返回值？
答：为了 实现链式表达式。                            // 2分
例如    int length = strlen( strcpy( strDest, “hello world”) );
*/


//#include <assert.h>
#include <stdio.h>

char *Mystrcpy(char *strDest, const char *strSrc) {
//    assert((strDest != NULL) && (strSrc != NULL));// 2分
    char *address = strDest;                        // 2分
    while ((*strDest++ = *strSrc++) != '\0');// 2分
    return address; // 2分
}

int main() {
    char desc[20] = {0};
    char src[20] = "Hello World";
    Mystrcpy(desc, src);
    printf("%s\n", desc);
    return 0;
}