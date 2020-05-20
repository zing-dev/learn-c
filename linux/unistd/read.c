//
// Created by zing on 5/20/2020.
//

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

const char *filename = "test.txt";

void read1() {
    int fd = creat(filename, 0777);
    if (fd == -1) {
        perror("create file");
        return;
    }
    char content[] = "this is test world\nhello world";
    ssize_t i = write(fd, content, sizeof(content));
    if (i == -1) {
        close(fd);
        perror("write");
        return;
    }
    printf("%zd\n", i);
    i = lseek(fd, 0, SEEK_SET);
    if (i == -1) {
        perror("lseek");
        return;
    }
    fd = open(filename, O_RDONLY);
    ssize_t i2;
    char buf[50] = {};
    i2 = read(fd, buf, sizeof(buf));
    if (i2 == -1) {
        close(fd);
        perror("read");
        return;
    }
    printf("%zd => %s\n", i2, buf);
}

void read2() {
    int fd = open(filename, O_RDONLY);
    char buf[10] = {};
    ssize_t i;
    while ((i = read(fd, buf, sizeof(buf))) != -1) {
        if (i == 0 || errno == EOF) {
            printf("read over\n");
            break;
        }
        printf("%zd => %s\n", i, buf);
    }
    if (i == -1) {
        close(fd);
        perror("read");
        return;
    }
    close(fd);
}

void read3() {
    char buf[BUFSIZ];
    ssize_t nr;
    int fd = open(filename, O_RDONLY);

    start:
    nr = read(fd, buf, BUFSIZ);
    if (nr == -1) {
        if (errno == EINTR)
            goto start; /* oh shush */
        if (errno == EAGAIN) {
            perror("EAGAIN");
        }
    } else {
        printf("%s\n", buf);
        printf("%lu\n", strlen(buf));
    }
}

void read4() {
    int len = 60;
    char *tmp = (char *) malloc(len);
    char *buf = tmp;
    ssize_t ret;
    int fd = open(filename, O_RDONLY);
    while (len != 0 && (ret = read(fd, buf, len)) != 0) {
        if (ret == -1) {
            if (errno == EINTR)
                continue;
            perror("read");
            break;
        }
        len -= ret;
        buf += ret;
    }

    printf("%s\n", tmp);
    free(tmp);
}

void read5(){
    int len = 10;
    char buf[10];
    ssize_t ret;
    int fd = open(filename, O_RDONLY);
    while (len != 0 && (ret = read(fd, buf, len)) != 0) {
        if (ret == -1) {
            if (errno == EINTR)
                continue;
            perror("read");
            break;
        }
        len -= ret;
        buf += ret;
    }
}
int main() {
    read1();
    read2();
    read3();
    read4();
    return 0;
}