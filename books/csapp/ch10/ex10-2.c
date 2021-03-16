/*
 * P608, 10.2
 */

#include "csapp.h"

int main() {
    int fd, fd1, fd2;
    char c;

    fd = creat("foobar.txt", 0777);
    if (fd == -1) {
        unix_error("creat");
    }
    if (fd != 0) {
        char str[] = "hello world";
        write(fd, str, sizeof(str));
        close(fd);
    }
    fd1 = Open("foobar.txt", O_RDONLY, 0);
    fd2 = Open("foobar.txt", O_RDONLY, 0);

    Read(fd1, &c, 1);
    Read(fd2, &c, 1);
    printf("c = %c\n", c);
    exit(0);
}
