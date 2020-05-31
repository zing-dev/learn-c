//
// Created by zing on 5/31/2020.
//

#include <stdarg.h>
#include <stdio.h>

void print_int(int len, ...) {
    va_list list;
    va_start(list, len);
    for (int i = 0; i < len; ++i) {
        int i1 = va_arg(list, int);
        printf("%d\t", i1);
    }
    printf("\n");
    va_end(list);
}

void print_char(int len, ...) {
    va_list list;
    va_start(list, len);
    for (int i = 0; i < len; ++i) {
        char i1 = va_arg(list, int);
        printf("%c\t", i1);
    }
    printf("\n");
    va_end(list);
}


int main(int argc, char *argv[]) {
    print_int(5, 1, 2, 3, 4, 5);
    print_int(5, 'a', 'b', 'c', 'd', 'e');
    print_char(5, 'a', 'b', 'c', 'd', 'e');
    return 0;
}
