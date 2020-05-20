//
// Created by zing on 5/20/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

/* Allocate SIZE bytes of memory.  */
int main() {
    char *c = (char *) malloc(sizeof(char));
    *c = 'a';
    printf("%p\n", c);
    printf("%c\n", *c);
    free(c);
    free(c);

    printf("char %lu\n", sizeof(char));
    printf("unsigned char * %lu\n", sizeof(unsigned char *));
    printf("u_char %lu\n", sizeof(u_char));
    printf("short %lu\n", sizeof(short));
    short *s = (short *) malloc(sizeof(short *));
    *s = 500;
    char *c2 = (char *) s;
    for (int i = 0; i < 2; i++) {
        printf("%.2x ", c2[i]);
        //fffffff4 01
    }
    ln();
    free(s);

    unsigned short *us = (unsigned short *) malloc(sizeof(unsigned short *));
    *us = 500;
    char *c3 = (char *) us;
    for (int i = 0; i < 2; i++) {
        printf("%.2x ", c3[i]);
        //ffffffff ffffffff
    }
    ln();
    free(us);
    return 0;
}