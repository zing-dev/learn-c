//
// Created by zing on 6/4/2020.
//

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd = creat("a.txt", O_RDWR);
    if (fd == -1) {
        perror("create");
        return errno;
    }
    char *str = "hello world";
    int ret = pwrite(fd, str, strlen(str), 5);
    if (ret == -1) {
        perror("pwrite");
        return errno;
    }
    return 0;
}