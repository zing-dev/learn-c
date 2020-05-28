//
// Created by zing on 5/28/2020.
//

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <errno.h>

int f_dupfd() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("read");
        return errno;
    }

    int dupfd = fcntl(fd, F_DUPFD);
    if (dupfd == -1) {
        perror("F_DUPFD");
        return errno;
    }
    printf("new fd %d\n", dupfd);

    char buf[16];
    bzero(buf, sizeof(buf));
    int ret = read(dupfd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        return errno;
    }
    if (ret == 0) {
        printf("read over\n");
        return errno;
    }
    printf("%s\n", buf);

    if (lseek(dupfd, 0, SEEK_SET) == -1) {
        perror("lseek");
        return errno;
    }

    memset(buf, 0, sizeof(buf));
    memmove(buf,"how old are you",sizeof(buf));
    ret = write(dupfd, buf, sizeof(buf));
    if (ret == -1) {
        perror("write");
        return errno;
    }
    printf("%s\n", buf);
    close(dupfd);
    close(fd);
    return 0;
}

int f_getfd(){
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("read");
        return errno;
    }

    int newfd = fcntl(fd, F_GETFD);
    if (newfd == -1) {
        perror("F_DUPFD");
        return errno;
    }
    printf("fd %d\n", fd);
    printf("new fd %d\n", newfd);
    return 0;
}
int main() {
    //return f_dupfd();
    return f_getfd();
}