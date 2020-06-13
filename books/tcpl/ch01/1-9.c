//
// Created by zing on 6/13/2020.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    int ch;
    int flag = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            if (flag == 0) {
                putchar('-');
            }
            flag = 1;
        } else {
            flag = 0;
            putchar(ch);
        }
    }
    return 0;
}
