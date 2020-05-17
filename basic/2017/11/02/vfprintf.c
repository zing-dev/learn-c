//
// Created by zhangrongxiang on 2017/11/2 10:24
// File vfprintf
//

#include <stdio.h>
#include <stdarg.h>

int WriteFrmtd(FILE *stream, char *format, ...) {
    va_list args;

    va_start(args, format);
    int i = vfprintf(stream, format, args);
    vfprintf(stdout, format, args);
    va_end(args);
    return i;
}

int main() {
    FILE *fp;

    fp = fopen("file.txt", "w");

    int i = WriteFrmtd(fp, "This is just one argument %d \n", 10);
    printf("%d\n", i);
    fclose(fp);

    return (0);
}