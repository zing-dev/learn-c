//
// Created by zhangrongxiang on 2018/1/16 10:18
// File 3
//

#include <stdio.h>
//统计空格、制表符和换行符个数的程序
int main() {
    int c, nb, nt, nl;
    nb = 0;
    nt = 0;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            nb++;
        else if (c == '\t')
            nt++;
        else if (c == '\n')
            nl++;
    }
    printf("%2d空格 %2dtab %2d换行\n", nb, nt, nl);
}