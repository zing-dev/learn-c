//
// Created by zhangrongxiang on 2017/10/12 10:08
// File show_byte
//

#include <stdio.h>
#include <stdlib.h>

void show_bytes(unsigned char *start, int len) {
    int i = 0;
    for (; i < len; ++i)
        printf(" %.2x", start[i]);
    printf("\n");
}

int main() {
    int a = -1;
    unsigned int b = 4294967295;
//  得到一个数的补码，先得到反码，然后将反码加上1，所得数称为补码

    /**
     * -1
     * 1000 0000 0000 0001 源码
     * 1111 1111 1111 1110 反码
     * 1111 1111 1111 1111 补码
     *
     *
     * 源码 ------>  补码
     * 取反 + 1
     * -1    取反
     * 补码 ------>  源码
     * 取反 + 1
     * -1   取反
     *
     */
    printf("a = %d, a = %u\n", a, a);
    printf("b = %d, b = %u\n", b, b);

    show_bytes((unsigned char *) &a, sizeof(int));
    show_bytes((unsigned char *) &b, sizeof(unsigned int));
    exit(0);
}