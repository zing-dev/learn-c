//
// Created by zhangrongxiang on 2018/1/16 10:20
// File 4
//

#include <stdio.h>
//将输入复制到输出的程序，并将其中连续的多个空格使用一个空格代替
int main() {
    int c;
    int nb;
    int prec = -1;
    while ((c = getchar()) != EOF) {
        if (c == ' ' && prec == ' ')
            continue;
        else {
            putchar(c);
            prec = c;
        }
    }
}