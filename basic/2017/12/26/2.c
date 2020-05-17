//
// Created by zhangrongxiang on 2017/12/26 17:51
// File 2
//

#include <stdio.h>
#include <limits.h>
void dec_to_bin(int n); //十进制转二进制,正负皆可

void to_binary(int n) {
    int r;
    r = n % 2;
    if (n >= 2) {
        to_binary(n / 2);
    }
    putchar('0' + r);
    return;
}

int main() {
    int n;
    dec_to_bin(-9);//负整数测试
    dec_to_bin(9);//正整数测试
    printf("enter a number(q to quit)!\n");
    while ((scanf("%d", &n)) == 1) {
        printf("Binary equivalent:");
        to_binary(n);
        printf("\n");
        printf("enter a number(q to quit):\n");
    }
    return 0;
}


void dec_to_bin(int n) //十进制转二进制,正负皆可
{
    unsigned int mask = 1 << sizeof(n) * CHAR_BIT - 1;
    int sp = 1;
    while (mask) {
        putchar(mask & n ? '1' : '0');
        if (sp++ % 4 == 0) putchar(' ');
        mask >>= 1;
    }
    putchar('\n');
}

//int main(void) {
//    dec_to_bin(-9);//负整数测试
//    dec_to_bin(9);//正整数测试
//    return 0;
//}
//---------------------------------------------------------------------------