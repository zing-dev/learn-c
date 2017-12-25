//
// Created by zhangrongxiang on 2017/9/12.
//
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define MAXBUF 256

int main() {
    struct sockaddr_in server;
    char *addr = "127.0.0.1";
    int port = 1995;
    int socketfd = 0;
    char buf[MAXBUF] = {0};

    bzero(&server, sizeof(server));

    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr(addr);
    server.sin_port = htons(port);

    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd < 0) {
        printf("create socket error ... ");
        return -1;
    }

    while (1) {
        memset(buf, 0, MAXBUF);
        fgets(buf, MAXBUF, stdin);
        int send = sendto(socketfd, buf, strlen(buf), 0,
                          (struct sockaddr *) &server,
                          sizeof(struct sockaddr)
        );

        if (send < 0) {
            perror("sendto error ....");
            break;
        } else {
            printf("send to %s(port=%d) len %d:%s\n",
                   addr, port, send, buf);
        }
    }

}