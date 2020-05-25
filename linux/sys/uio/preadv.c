//
// Created by zing on 5/25/2020.
//
#include <sys/uio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    struct iovec buf[1];
    buf[0].iov_base = malloc(sizeof(char) * 10);
    buf[0].iov_len = 10;
    int fd = open("buccaneer.txt", O_RDONLY);
    if (fd == -1) {
        return errno;
    }

    ssize_t i = preadv(fd, buf, 1, 0);
    if (i == -1) {
        perror("preadv");
        return errno;
    }
    printf("%d %s\n", (int) buf[0].iov_len, (char *) buf[0].iov_base);
    lseek(fd,0,SEEK_SET);
    i = preadv(fd, buf, 1, 10);
    if (i == -1) {
        perror("preadv");
        return errno;
    }
    printf("%d %s\n", (int) buf[0].iov_len, (char *) buf[0].iov_base);

}