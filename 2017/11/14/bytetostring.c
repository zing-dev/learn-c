//
// Created by zhangrongxiang on 2017/11/14 14:33
// File bytetostring
//

#include <stdio.h>
#include <string.h>

void byteToString(unsigned char *buffer, int len, unsigned char *string);

int main() {

    unsigned char *str = "hello";
    char buf[20];
    byteToString(str, sizeof(str), buf);
    printf("%s\n", buf);
}

void byteToString(unsigned char *buffer, int len, unsigned char *string) {
    int i = 0;
    int tmp;
    for (i = 0; i < len; i++) {
        tmp = buffer[i] >> 4;
        if (tmp >= 0 && tmp <= 9)
            string[i * 2] = tmp + '0';
        else if (tmp >= 10 && tmp <= 15)
            string[i * 2] = tmp - 10 + 'A';
        else
            string[i * 2] = 'F';

        tmp = buffer[i] & 0xF;
        if (tmp >= 0 && tmp <= 9)
            string[i * 2 + 1] = tmp + '0';
        else if (tmp >= 10 && tmp <= 15)
            string[i * 2 + 1] = tmp - 10 + 'A';
        else
            string[i * 2 + 1] = 'F';
    }
    string[i * 2] = '\0';
}
