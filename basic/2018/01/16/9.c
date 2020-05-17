//
// Created by zhangrongxiang on 2018/1/16 10:35
// File 9
//

#include <stdio.h>

#define TABINC 8
//将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止的地方。假设制表符终止的位置是固定的，
// 比如每隔n列就会出现一个制表符终止位。n应该作为变量还是常量呢？
int main() {
    int c, nb, pos;
    nb = 0;
    pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0) {
                putchar(' ');
                pos++;
                nb--;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            pos++;
        }
    }
}