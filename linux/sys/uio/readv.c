//
// Created by zing on 5/25/2020.
//

#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int readv1() {
    int fd = open("buccaneer.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        if (errno == EPERM) {
            printf("权限不够\n");
            return 0;
        }
    }
    char buf[256] = {};
    int ret = read(fd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        return errno;
    }
    printf("%s\n", buf);

    ret = lseek(fd, 0, SEEK_SET);
    if (ret == -1) {
        perror("lseek");
        return errno;
    }

    memset(buf, 0, sizeof(buf));
    ret = read(fd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        return errno;
    }
    printf("%s\n", buf);

    lseek(fd, 0, SEEK_SET);
    struct iovec iov[3] = {};
    for (int i = 0; i < 3; i++) {
        iov[i].iov_len = 30;
        iov[i].iov_base = malloc(sizeof(char) * 30);
    }
    ret = readv(fd, iov, 3);
    if (ret == -1) {
        perror("readv");
        return errno;
    }
    for (int i = 0; i < 3; i++) {
        printf("%d\t%s\n", (int) iov[i].iov_len, (char *) iov[i].iov_base);
    }
    close(fd);
    return 0;
}

int readv2() {
    int fd;
    struct iovec buffers[2];
    buffers[0].iov_len = 20;
    buffers[0].iov_base = malloc(sizeof(char) * 20);
    buffers[1].iov_len = 30;
    buffers[1].iov_base = malloc(sizeof(char) * 30);
    fd = open("buccaneer.txt", O_RDONLY);
    if (fd == -1) {
        return errno;
    }
    int count = readv(fd, buffers, 2);
    close(fd);
    char *str1 = buffers[0].iov_base;
    char *str2 = buffers[1].iov_base;
    printf("total %d\n", count);
    printf("%lu\t%s\n", strlen(str1), str1);
    printf("%lu\t%s\n", strlen(str2), str2);
    return 0;
}

int main() {
    readv1();
    readv2();
}