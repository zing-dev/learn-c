//
// Created by zhangrongxiang on 2017/10/25 17:21
// File caddr_t
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dumpbuf(char *data, int len);

int main() {
    char *str = "hello world" \
    "what is your name!!";
    dumpbuf(str, strlen(str) + 1);
}

void dumpbuf(char *data, int len) {
    caddr_t buf;
    size_t buflen;
    int i = 0, j = 0;
    buflen = (len * 2) + (len / 4) + (len / 32) + 3;
    buf = malloc(buflen);
    while (j < len) {
        if (j % 32 == 0)
            buf[i++] = '\n';
        else if (j % 4 == 0)
            buf[i++] = ' ';
        snprintf(&buf[i], buflen - i, "%02x", ((unsigned char *) data)[j] & 0xff);
        i += 2;
        j++;
    }
    if (buflen - i >= 2) {
        buf[i++] = '\n';
        buf[i] = '\0';
    }
    printf("%s\n", buf);
    free(buf);
}