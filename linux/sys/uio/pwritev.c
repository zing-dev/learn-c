//
// Created by zing on 5/25/2020.
//
#include <sys/uio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_WRONLY| O_CREAT|O_TRUNC);
    if (fd == -1){
        perror("open");
        return errno;
    }
    struct iovec iov[2];
    for (int i = 0; i < 2; i++) {
        iov[i].iov_len = 10;
        iov[i].iov_base = "=1234567890";
    }
    int ret = pwritev(fd, iov, 2, 5);
    if (ret == -1) {
        perror("pwritev");
        return errno;
    }
    printf("%d\n", ret);
    return 0;
}