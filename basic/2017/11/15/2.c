//
// Created by zhangrongxiang on 2017/11/15 17:22
// File 2
//


#include <stdio.h>
#include "main.h"

int main() {
    int i = 0;
    change(&i);
    printf("%d\n", i);
    printf("%d\n", htonl(i));
    printf("%d\n", ntohl(i));
    printf("%d\n", htons(16));
}

