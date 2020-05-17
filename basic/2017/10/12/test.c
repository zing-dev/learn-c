//
// Created by zhangrongxiang on 2017/10/12 9:32
// File test
//

#include <stdio.h>

int main() {
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char *) &x;
//    78 56 34 12
    printf("%0x %0x %0x %0x\n", p[0], p[1], p[2], p[3]);
    printf("%x\n", x);
    printf("%d\n", sizeof(unsigned int));
    //65536
    printf("%d\n", 1 << 16);
    printf("%u\n", 1 << 32 - 1);
    printf("%o\n", 1 << 32 - 1);
    printf("%x\n", 1 << 32 - 1);

    printf("%d\n", 4294967295);
    return 0;
}