/*
 * P608, 习题10.3
 */
#include "csapp.h"
int main() {
    int fd;
    char c;

    fd = Open("foobar.txt", O_RDONLY, 0);
    if (Fork() == 0) {      /* child */
        printf("child process\n");
        Read(fd, &c, 1);
        printf("child c = %c\n", c);
        exit(0);
    }

    if (Fork() == 0) {      /* child */
        printf("child2 process\n");
        Read(fd, &c, 1);
        printf("child2 c = %c\n", c);
        exit(0);
    }

    /* parent */
    Wait(NULL);
    printf("parent process\n");
    Read(fd, &c, 1);
    printf("parent c = %c\n", c);
    exit(0);
}
