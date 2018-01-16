//
// Created by zhangrongxiang on 2018/1/16 10:24
// File 6
//

#include <stdio.h>
//打印输入中单词长度的直方图。水平方向的直方图比较容易绘制，垂直方向的直方图则要困难写。

#define MAXHIST 15
#define MAXWORD 11

int word_stats(int wl[]) {
    int flag;
    int c, nc, i, ovflow;
    flag = 0;
    nc = 0;
    ovflow = 0;
    for (i = 0; i < MAXWORD; i++)
        wl[i] = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (flag) {
                flag = 0;
//                if(nc>0)
                if (nc < MAXWORD)
                    wl[nc]++;
                else
                    ovflow++;
                nc = 0;
            }
        } else if (!flag) {
            flag = 1;
            nc = 1;
        } else
            nc++;
    }
    return ovflow;
}

void hist_h(int wl[]) {
    int i;
    int maxvlaue = 0;
    int len;
    for (i = 1; i < MAXWORD; i++)
        if (wl[i] > maxvlaue)
            maxvlaue = wl[i];
    for (i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d :", i, wl[i]);
        if (wl[i] > 0) {
            if ((len = wl[i] * MAXHIST / maxvlaue) <= 0)
                len = 1;
        } else
            len = 0;
        while (len > 0) {
            putchar('*');
            len--;
        }
        putchar('\n');
    }
}

void hist_v(int wl[]) {
    int i, j;
    int maxvlaue = 0;
    int len;
    for (i = 1; i < MAXWORD; i++)
        if (wl[i] > maxvlaue)
            maxvlaue = wl[i];
    for (i = MAXHIST; i > 0; i--) {
        for (j = 1; j < MAXWORD; j++)
            if (wl[j] * MAXHIST / maxvlaue >= i)
                printf("   * ");
            else
                printf("     ");
        putchar('\n');
    }
    for (i = 1; i < MAXWORD; i++)
        printf("%4d ", i);
    putchar('\n');
    for (i = 1; i < MAXWORD; i++)
        printf("%4d ", wl[i]);
    putchar('\n');
}

int main() {
    int wl[MAXWORD];
    int ovflow;
    ovflow = word_stats(wl);
    hist_h(wl);
    hist_v(wl);
    if (ovflow)
        printf("Overflow: %d\n", ovflow);
}