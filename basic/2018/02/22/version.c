//
// Created by zhangrongxiang on 2018/2/22 15:26
// File version
//

#include <stdio.h>

#define KERNEL_VERSION(a, b, c) (((a) << 16) + ((b) << 8) + (c))

int main() {
    int i = 0, j = 0, k = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                printf("%d\n", KERNEL_VERSION(i, j, k));
            }
        }
    }
    return 0;
}