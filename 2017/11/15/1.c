//
// Created by zhangrongxiang on 2017/11/15 14:44
// File 1
//


#include <stdio.h>
#include <stdlib.h>

#define  HEAD_REGISTER_USER            0X0000003E    //注册客户端
#define  HEAD_USER_ONLINE_ACK            0x10000037
#define  HEAD_DB_LOG            0x0000004D    //日志

int main() {
    printf("%d\n", HEAD_REGISTER_USER);
    printf("%d\n", HEAD_USER_ONLINE_ACK);
    printf("%u\n", HEAD_USER_ONLINE_ACK);
    printf("%x\n", HEAD_USER_ONLINE_ACK);
    printf("%x\n", HEAD_REGISTER_USER);
    printf("%X\n", HEAD_REGISTER_USER);
    printf("%u\n", 268435510);
    printf("---------------------------------\n");
    printf("HEAD_REGISTER_USER |= 0x10000000   %X \n", HEAD_REGISTER_USER | 0x10000000);

    printf("---------------------------------\n");
    printf("%d\n", 0x4b); //75
    printf("%d\n", 0x4b - 0x00000035); //22
    printf("%X\n", 0x00000035 + 24);
    printf("%d\n", 0x4D - 0x00000035); //24
    printf("HEAD_DB_LOG |= 0x10000000   %X \n", HEAD_DB_LOG | 0x10000000);

    printf("---------------------------------\n");
    printf("%d\n", 0x0000003e - 0x00000035); //24
    printf("%d\n", 0x0000003f - 0x00000035); //24
    printf("%d\n", 0x00000040 - 0x00000035); //24
    printf("%d\n", 0x00000037 - 0x00000035); //24
    printf("%d\n", 0x00000038 - 0x00000035); //24


}
