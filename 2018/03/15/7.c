//
// Created by zhangrongxiang on 2018/3/15 16:17
// File 7
//

#include<stdio.h>
//#include<assert.h>

int Mystrlen(const char *str) {  // 输入参数const
//    assert(str != NULL);  // 断言字符串地址非0
    int len = 0;
    while ((*str++) != '\0') {
        len++;
    }
    return len;
}

int main() {
    char str[] = "Hello World";
    printf("%d\n", Mystrlen(str));//11
    printf("%d\n", (int) sizeof(str));//12
}