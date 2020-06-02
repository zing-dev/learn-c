//
// Created by zing on 6/2/2020.
//
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <strings.h>

/* Create a new stream that refers to an existing system file descriptor.  */
int main() {
    int fd = open("a.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return errno;
    }
    FILE *file = fdopen(fd, "r");
    if (file == NULL) {
        perror("fdopen");
        return errno;
    }
    char buf[16];
    bzero(buf, sizeof(buf));
    size_t i = fread(buf, 1, sizeof(buf) - 1, file);
    if (i == 0) {
        printf("none read\n");
        return 0;
    }
    printf("%s\n", buf);
}