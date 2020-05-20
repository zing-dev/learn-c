//
// Created by zing on 5/20/2020.
//

#ifndef LEARN_C_UTILS_H
#define LEARN_C_UTILS_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

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

#endif //LEARN_C_UTILS_H
