//
// Created by zing on 6/4/2020.
//
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <strings.h>

int main() {
    int fd = open("Makefile", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return errno;
    }
    char content[24] = {0};
    int ret = pread(fd, content, sizeof(content) - 1, 0);
    if (ret == -1) {
        perror("pread");
        return 0;
    }
    if (ret == 0) {
        printf("read over\n");
    } else {
        printf("%s\n", content);
    }
    lseek(fd, 0, SEEK_SET);
    bzero(content, sizeof(content));
    ret = pread(fd, content, sizeof(content) - 1, 5);
    if (ret == -1) {
        perror("pread");
        return 0;
    }
    if (ret == 0) {
        printf("read over\n");
    } else {
        printf("%s\n", content);
    }
    return 0;
}