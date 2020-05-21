//
// Created by zing on 5/20/2020.
//

#ifndef LEARN_C_UTILS_H
#define LEARN_C_UTILS_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

//extern int printf (const char *__restrict __format, ...);
extern void println(const char *format, ...) {
    va_list arg_list;
    va_start(arg_list, format);
    char dest[strlen(format) + 1];
    strcat(dest, format);
    strcat(dest, "\n");
    strcat(dest, "\0");
    vprintf(dest, arg_list);
    va_end(arg_list);
}

extern void ln() {
    printf("\n");
}

extern void print_int_arr(const int *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d \t", arr[i]);
    }
    ln();
}

extern void print_char_arr(const char *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c \t", arr[i]);
    }
    ln();
}

extern void str_lower(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (char) tolower((int) str[i]);
    }
}

extern void str_upper(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (char) toupper((int) str[i]);
    }
}

/**
 * @param arr
 * @param len
 * @return
 *
 * todo check ??
 */
extern char *arr_net_addr(const int *arr, int len) {
    struct in_addr addr;
    addr.s_addr = 0;
    for (int i = 0; i < len; i++) {
        addr.s_addr += arr[i] << i * 8;
    }
    return inet_ntoa(addr);
}

#endif //LEARN_C_UTILS_H
