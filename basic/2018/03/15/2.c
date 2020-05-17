//
// Created by zhangrongxiang on 2018/3/15 11:10
//

#include <stdio.h>
union {
    int i;
    char x[2];
} a;

void main() {
    a.x[0] = 10;
    a.x[1] = 1;
    printf("%d", a.i);//266
}