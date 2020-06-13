//
// Created by zing on 6/13/2020.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            putchar('\\');
            putchar('\t');
        } else if (ch == '\\') {
            putchar('\\');
            putchar('\\');
        } else if (ch == '\b') {
            putchar('\\');
            putchar('\b');
        } else {
            putchar(ch);
        }
    }
    return 0;
}
