//
// Created by zhangrongxiang on 2018/1/25 11:10
// File or
//

#include <stdio.h>

int true() {
    return 1;
}

int false() {
    return !true();
}

int main() {
    int a = 1;
    int b = 0;
    int c = a || b;
    int d = a && b;
    int e = true() || false();
    printf("c --> %d\n", c);
    printf("d --> %d\n", d);
    printf("e --> %d\n", e);

}