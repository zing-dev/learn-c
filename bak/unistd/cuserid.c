//
// Created by zhangrongxiang on 2018/2/26 13:39
// File cuserid
//

#include <stdio.h>

int main() {
    char str[16];
    if (cuserid(str) != 0) {
        printf("%s\n", str);
    }
    return 0;
}