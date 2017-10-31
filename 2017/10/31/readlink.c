//
// Created by zhangrongxiang on 2017/10/31 16:07
// File readlink
//

#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 1024

int main(void) {
    char sympath[] = "/tmp/mysymlink";
    ssize_t size;
    char buf[BUFFSIZE];

//    ssize_t readlink(const char* restrict pathname, char *restrict buf, size_t bufsize);
    if ((size = readlink(sympath, buf, BUFFSIZE)) < 0) {
        printf("readlink error for %s\n", sympath);
        return 1;
    } else {
        buf[size] = '\0';
        printf("%s\n", buf);
    }

    return 0;

}