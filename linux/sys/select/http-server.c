//
// Created by zing on 5/26/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:ip address and port numbers\n");
        return -1;
    }

    const char *ip = argv[1];
    const int port = (const int) strtol(argv[2], NULL, 10);
    printf("ip %s\n", ip);
    printf("port %d\n", port);

    int ret = 0;
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_aton(ip, &addr.sin_addr);
    //inet_pton(AF_INET,ip,&addr.sin_addr);

    int fd = socket(AF_INET, SOCK_STREAM, PF_UNSPEC);
    if (fd == -1) {
        perror("socket");
        return errno;
    }

    ret = bind(fd, (struct sockaddr *) &addr, sizeof(addr));
    if (ret == -1) {
        perror("bind");
        return errno;
    }

    ret = listen(fd, 10);
    if (ret == -1) {
        perror("listen");
        return errno;
    }

    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);

    int conn = accept(fd, (struct sockaddr *) &client, &client_len);
    if (conn == -1) {
        perror("accept");
        return errno;
    }

    char buf[128];
    fd_set rds;
    fd_set wds;
    fd_set eds;
    FD_ZERO(&rds);
    FD_ZERO(&wds);
    FD_ZERO(&eds);
    struct timeval tv;
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    while (1) {
        bzero(buf, sizeof(buf));
        FD_SET(conn, &rds);
        FD_SET(conn, &wds);
        FD_SET(conn, &eds);

        ret = select(conn + 1, &rds, &wds, &eds, &tv);
        if (ret == -1) {
            perror("select");
            return errno;
        }

        if (FD_ISSET(conn, &rds)) {
            ssize_t i = read(conn, buf, sizeof(buf));
            if (i == -1) {
                perror("read");
            } else if (i == 0) {
                printf("nothing read\n");
            } else {
                printf("from client => %s\n", buf);
                i = write(conn, buf, strlen(buf) + 1);
                if (i == -1) {
                    perror("write");
                } else if (i == 0) {
                    printf("nothing wrote\n");
                } else {
                    printf("wrote %zd byte\n", i);
                }
            }
        }
       /* if (FD_ISSET(conn, &wds)) {
            char *str = "hello from server\n";
            ssize_t i = write(conn, str, strlen(str) + 1);
            if (i == -1) {
                perror("write");
            } else if (i == 0) {
                printf("nothing wrote\n");
            } else {
                printf("wrote %zd byte\n", i);
            }
        }*/
        if (FD_ISSET(conn, &eds)) {
            printf("conn %d happen exception\n", conn);
            close(conn);
        }
    }
}