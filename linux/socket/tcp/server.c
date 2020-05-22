//
// Created by zing on 5/22/2020.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_BUF  256

int main() {

    struct sockaddr_in server;
    server.sin_addr.s_addr = INADDR_ANY;//inet_addr("192.168.0.111");
    server.sin_family = AF_INET;
    server.sin_port = htons(1234);

    int fd = socket(AF_INET, SOCK_STREAM, PF_UNSPEC);
    if (fd == -1) {
        perror("socket");
        return errno;
    }

    if (bind(fd, (const struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("bind");
        return errno;
    }

    if (listen(fd, 10) == -1) {
        perror("listen");
        return errno;
    }

    while (1) {
        struct sockaddr_in client;
        socklen_t client_len = sizeof(client);

        printf("等待新的客户端连接\n");
        int client_fd = accept(fd, (struct sockaddr *) &client, &client_len);
        printf("ip为 %s 的客户端连接\n", inet_ntoa(client.sin_addr));
        if (client_fd == -1) {
            break;
        }
        char buf[MAX_BUF];
        while (1) {
            printf("等待ip为 %s 的客户端发送数据\n", inet_ntoa(client.sin_addr));
            bzero(&buf, MAX_BUF);
            ssize_t i = recv(client_fd, buf, MAX_BUF, 0);
            if (i == -1) {
                perror("recv");
                break;
            }
            if (i == 0) {
                printf("ip为 %s 的客户端断开连接\n", inet_ntoa(client.sin_addr));
                break;
            }
            if (i > 0) {
                printf("%zd %s\n", i, buf);
                send(client_fd, buf, strlen(buf), 0);
            }
        }
    }
    close(fd);
    return 0;
}