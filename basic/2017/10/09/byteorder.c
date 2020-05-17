//
// Created by zhangrongxiang on 2017/10/9 17:58
// File byteorder
//

#include <stdio.h>

int main(int argc, char **argv) {
    union {
        short s;
        char c[sizeof(short)];
//        int i;
//        char ch[sizeof(int)];
    } un;
    printf("short is %d\n", sizeof(short));
    un.s = 0x0102;
//    un.i = 0x11001001;
    if (un.c[0] == 1 && un.c[1] == 2) {
        puts("字节序为大端 big");
    } else if (un.c[0] == 2 && un.c[1] == 1) {
        puts("字节序为小端 small");
    } else {
        puts("字节序未知 un know");
    }
//    printf("0 %d\n",un.ch[0]);
//    printf("1 %d\n",un.ch[1]);
//    printf("2 %d\n",un.ch[2]);
//    printf("3 %d\n",un.ch[3]);
    short int x;
    char x0, x1;
    x = 0x1122;
    x0 = ((char *) &x)[0];  //低地址单元
    x1 = ((char *) &x)[1];  //高地址单元
    printf("x0=0x%x,x1=0x%x", x0, x1);
    // 若x0=0x11,则是大端; 若x0=0x22,则是小端......

    /**
     * 所谓的大端模式，
     * 是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
     *
     * 所谓的小端模式，
     * 是指数据的低位保存在内存的低地址中，而数据的高位保存在内存的高地址中。
     */
    return 0;

}