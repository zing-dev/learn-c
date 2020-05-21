//
// Created by zing on 5/21/2020.
//

#include <stdio.h>

union {
    char ch;
    int i;
} un;

int main(void) {
    un.i = 0x12345678;
    if (un.ch == 0x12) {
        printf("big endpoint\n");
    } else {
        printf("small endpoint\n");
    }

    unsigned short tt = 0x1234;
    unsigned char ge;
    ge = ((unsigned char *) &tt)[0];
    if (ge == 0x12) {
        printf("Big endpoint\r\n");
    } else if (ge == 0x34) {
        printf("small endpoint\r\n");
    }
    return 0;
}