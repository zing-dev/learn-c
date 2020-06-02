//
// Created by zing on 6/2/2020.
//
#include <stdio.h>
#include <errno.h>
#include <strings.h>

//|     r       │ O_RDONLY                      │
//├─────────────┼───────────────────────────────┤
//│     w       │ O_WRONLY | O_CREAT | O_TRUNC  │
//├─────────────┼───────────────────────────────┤
//│     a       │ O_WRONLY | O_CREAT | O_APPEND │
//├─────────────┼───────────────────────────────┤
//│     r+      │ O_RDWR                        │
//├─────────────┼───────────────────────────────┤
//│     w+      │ O_RDWR | O_CREAT | O_TRUNC    │
//├─────────────┼───────────────────────────────┤
//│     a+      │ O_RDWR | O_CREAT | O_APPEND
int main() {
    FILE *file = fopen("Makefile", "r");
    if (file == NULL) {
        perror("fopen");
        return errno;
    }
    char buf[20];
    bzero(buf, sizeof(buf));
    size_t i = fread(buf, 1, sizeof(buf) - 1, file);
    if (i == 0) {
        printf("none read\n");
        return 0;
    }
    printf("%s\n", buf);

    file = freopen("a.txt", "w+", file);
    if (file == NULL) {
        ferror(file);
        return fileno(file);
    }
    fseek(file, 0, SEEK_SET);
    i = fwrite(buf, 1, sizeof(buf), file);
    if (i == 0) {
        printf("none write\n");
        return 0;
    }
    fseek(file, 0, SEEK_SET);
    char buf2[5];
    i = fread(buf2, sizeof(char), sizeof(buf2) - 1, file);
    if (i == 0) {
        printf("none read\n");
        return 0;
    }
    printf("=> %s\n", buf2);
    fclose(file);
}