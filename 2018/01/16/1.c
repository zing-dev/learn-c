//
// Created by zhangrongxiang on 2018/1/16 9:51
// File 16
//

#include <stdio.h>

// 单词计数
int main() {
    int c, nl, nw, nc, flag;
    flag = 0;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == 'q')
            break;
        ++nc;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t')
            flag = 0;
        else if (!flag) {
            flag = 1;
            ++nw;
        }
    }
    printf("%3d %3d %3d\n", nl + 1, nw, nc);
    return 0;
}