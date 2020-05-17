//
// Created by zhangrongxiang on 2018/2/22 14:01
// File attribute3
//

#include <stdio.h>

struct {
    int a;
    char b;
    short c;
}pp1;

struct p {
    int a;
    char b;
    short c;
}__attribute__((aligned(4))) pp;

struct m {
    char a;
    int b;
    short c;
}__attribute__((aligned(4))) mm;

struct o {
    int a;
    char b;
    short c;
} oo;

struct x {
    int a;
    char b;
    struct p px;
    short c;
}__attribute__((aligned(8))) xx;

int main() {
    //(int)4 (short)2 (char)1
    printf("sizeof(int)=%d,sizeof(short)=%d.sizeof(char)=%d\n", (int) sizeof(int), (int) sizeof(short),
           (int) sizeof(char));
    //pp=8 sizeof(a)+sizeof(b)+sizeof(c)=4+1+1=6<8 所以sizeof(pp)=8

    // mm=12 sizeof(a)+sizeof(b)+sizeof(c)=1+4+2=7
    // 但是 a 后面需要用 3 个字节填充，但是 b 是 4 个字节，所以 a 占用 4 字节， b 占用 4 个字节，而 c 又要占用 4 个字节。所以 sizeof(mm)=12
    printf("pp=%d,mm=%d \n", (int) sizeof(pp), (int) sizeof(mm));
    //oo=8 sizeof(a)+sizeof(b)+sizeof(c)=4+1+2=7 因为默 认是以4 字节对齐，所以sizeof(oo)=8

    // xx=24
    //sizeof(a)+ sizeof(b)=4+1=5
    //sizeof(pp)=8; 即xx 是采用8 字节对齐的，所以要在a ，b 后面添3 个空余字节，然后才能存储px ，
    //4+1+ （3 ）+8+1=17
    //因为xx 采用的对齐是8 字节对齐，所以xx 的大小必定是8 的整数倍，即xx 的大小是一个比17 大又是8 的倍数的一个最小值，由此得到
    //17<24 ，所以sizeof(xx)=24
    printf("oo=%d,xx=%d \n", (int) sizeof(oo), (int) sizeof(xx));
    //8
    printf("pp1 =%d\n",(int) sizeof(pp1));
    return 0;
}