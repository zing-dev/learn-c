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

int main(int argc, char *argv[]) {
    int port = 1995;
    int s = 0;
    int reuse = 0;
    int recv = 0;
    char buf[MAXBUF] = {0};
    struct sockaddr_in server, client;
    int sock_len = sizeof(struct sockaddr);

    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        perror("create socket error ... ");
        return -1;
    }

    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind error ...");
        return -1;
    }
    printf("server recvfrom........................................\n");
    while (1) {
        memset(buf, 0, MAXBUF);
        recv = recvfrom(
                s,
                buf,
                MAXBUF,
                0,
                (struct sockaddr *) &client,
                &sock_len
        );

        if (recv < 0) {
            perror("recvfrom error ... \n");
            break;
        } else {
            printf("receive msg from %s(port=%d) len %d: %s\n", inet_ntoa(client.sin_addr), port, recv, buf);
        }
    }
    return 0;
}