//
// Created by zing on 6/7/2020.
//

#include <stdio.h>

void getchar1() {
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

void getchar2() {
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

void getchar3() {
    int c;
    while ((c = getchar()) != 0)
        putchar(c);
}

void getchar4() {
    int c;
    while ((c = getchar()) != 1)
        putchar(c);
}


void getchar5() {
    int c;
    while ((c = getchar()) != -1)
        putchar(c);
}

void getchar6() {
    int c;
    while ((c = getchar()) != -1)
        putchar(c);
}

int main(int argc, char *argv[]) {
    printf("%c %d\n", EOF, EOF);
    getchar6();
    return 0;
}
