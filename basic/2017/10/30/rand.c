//
// Created by zhangrongxiang on 2017/10/30 14:11
// File rand
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int getRandom(unsigned char *Buff, int len);

int main() {
    unsigned char buff[16] = {0x00};
    int i = 0;
    while (i++ < 100) {
        srand((unsigned) time(NULL));
        getRandom(buff, 16);
        printf("%s\n", buff);
        sleep(1);
    }

    return 0;
}

int getRandom(unsigned char *Buffer, int len) {
    long i = 0, reman = 0, rand = 0;
    reman = len % 4;
//    printf("1--------------------\n");
    for (i = 0; i < len / 4; i++) {
//        printf("2--------------------\n");
        rand = random();
//        printf("%ld\n", rand);
//        printf("22--------------------\n");
        memcpy(Buffer + i * 4, &rand, 4);
//        printf("%s\n", Buffer);
    }
    if (reman > 0) {
//        printf("3--------------------\n");
        rand = random();
        memcpy(Buffer + i * 4, &rand, reman);
    }
//    printf("--------------------\n");
    return 0;
}
