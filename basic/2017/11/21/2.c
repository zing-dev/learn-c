//
// Created by zhangrongxiang on 2017/11/21 14:17
// File 2
//

#include <stdlib.h>
#include <stdio.h>

void main() {
    char a[] = "1000000000";
    char b[] = "1000000000";
    char c[] = "ffff";
    char d[] = "0x42532075";
    printf("a=%d\n", strtol(a, NULL, 10));
    printf("b=%d\n", strtol(b, NULL, 2));
    printf("c=%d\n", strtol(c, NULL, 16));
    printf("d=%X\n", strtol(d, NULL, 16));
}