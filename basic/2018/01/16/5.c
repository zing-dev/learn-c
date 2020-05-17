//
// Created by zhangrongxiang on 2018/1/16 10:22
// File 5
//
#include <stdio.h>

//以每行一个单词的形式打印其输入
int main() {
    int c;
    int flag;
    flag = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (flag) {
                putchar('\n');
                flag = 0;
            }
        } else if (!flag) {
            flag = 1;
            putchar(c);
        } else {
            putchar(c);
        }
    }
}