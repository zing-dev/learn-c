/*
 * P609, 习题10.5
 */

#include "csapp.h"

int main() {
    int fd1, fd2;
    char c;

    fd1 = Open("foobar.txt", O_RDONLY, 0);
    fd2 = Open("foobar.txt", O_RDONLY, 0);
    Read(fd2, &c, 1);
    int i = Dup2(fd2, fd1);
    printf("fd1 = %d\n", fd1);
    printf("fd1 = %d\n", fd2);
    printf("dup2 = %d\n", i);
    Read(fd1, &c, 1);
    printf("c = %c\n", c);
    exit(0);
}
