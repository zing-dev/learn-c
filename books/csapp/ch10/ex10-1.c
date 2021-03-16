/*
 *P598 , 10.1
 */

#include "csapp.h"

int main() {
    int fd1, fd2;
    char c;

    int f1 = creat("foobar.txt", 0x777);
    int f2 = creat("baz.txt", 0x777);
    fd1 = Open("foobar.txt", O_RDONLY, 0);
    Close(fd1);
    fd2 = Open("baz.txt", O_RDONLY, 0);

    printf("f1 = %d\n", f1);
    printf("fd1 = %d\n", fd1);
    printf("f2 = %d\n", f2);
    printf("fd2 = %d\n", fd2);
    exit(0);
}
