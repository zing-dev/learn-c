//
// Created by zing on 5/26/2020.
//

#include <sys/select.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#pragma ide diagnostic ignored "hicpp-signed-bitwise"

int main() {
    fd_set rd;
    struct timeval tv;
    int err;
    FD_ZERO(&rd);
    FD_SET(0, &rd);
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    FD_SET(STDIN_FILENO, &rd);

    err = select(1, &rd, NULL, NULL, &tv);
    if (err == 0) {
        //超时
        printf("select time out!\n");
    } else if (err == -1) {
        //失败
        printf("fail to select!\n");
    } else {
        //成功
        printf("data is available!\n");
        if (FD_ISSET(STDIN_FILENO, &rd)) {
            char buf[256];
            bzero(buf, sizeof(buf));
            int ret = read(STDIN_FILENO, buf, sizeof(buf) - 1);
            if (ret <= 0) {
                perror("recv");
                return 0;
            }
            printf("get %d bytes of normal data: %s \n", ret, buf);
        }
    }
    return 0;
}
