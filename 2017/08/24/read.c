//
// Created by zhangrxiang on 17-8-24.
//

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
    char buf[1024];
    int n;
    n = read(STDIN_FILENO, buf, 10);
    if (n < 0) {
        perror("read STDIN_FILENO");
        exit(1);
    }
    buf[0] = 'F';
    write(STDOUT_FILENO, buf, n);
//    memset(buf, 0, sizeof(buf));
//    int fd = open("/dev/tty", O_RDONLY|O_NONBLOCK);
//    read(fd, buf, sizeof(buf));
//    write(STDOUT_FILENO, buf, n);
    return 0;
}
