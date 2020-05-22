//
// Created by zing on 5/22/2020.
//

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 256

int main() {
    struct sockaddr_in client;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    client.sin_family = AF_INET;
    client.sin_port = htons(1234);
    socklen_t client_len = sizeof(client);
    int fd = socket(AF_INET, SOCK_STREAM, PF_UNSPEC);
    if (fd == -1) {
        perror("socket");
        return errno;
    }
    if (connect(fd, (const struct sockaddr *) &client, client_len) == -1) {
        perror("connect");
        return errno;
    }
    printf("========connect server success=========\n");
    char buf[MAX_BUF];
    while (1) {
        bzero(&buf, MAX_BUF);
        fgets(buf, MAX_BUF, stdin);
        //ssize_t i = sendto(fd, buf, strlen(buf), 0, (const struct sockaddr *) &client, client_len);
        ssize_t i = send(fd, buf, strlen(buf), 0);
        if (i == -1) {
            perror("sendto");
            break;
        }
        bzero(&buf, MAX_BUF);
        struct sockaddr_in server;
        bzero(&server, sizeof(server));
        socklen_t length = sizeof(server);
        i = recvfrom(fd, buf, MAX_BUF, 0, (struct sockaddr *) &server, &length);
        if (i == -1) {
            perror("recv");
            break;
        }
        if (i > 0) {
            printf("recv from server %zd => %s", i, buf);
        }
    }
    return 0;
}