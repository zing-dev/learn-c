/*
 * p632
 *
 * 迭代 echo 服务器的主程序
 *
 * unix> cc -I../../common ../../common/csapp.c echoserveri.c echo.c -lpthread -o echod
 */

#include "csapp.h"

void echo(int connfd);

int main(int argc, char **argv) {
    int listenfd, connfd, port, clientlen;
    struct sockaddr_in clientaddr;
    struct hostent *hp;
    char *haddrp;
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }
    port = atoi(argv[1]);

    listenfd = Open_listenfd(port);
    while (1) {
        clientlen = sizeof(clientaddr);
        connfd = Accept(listenfd, (SA * ) & clientaddr, &clientlen);

        /* Determine the domain name and IP address of the client */
        hp = Gethostbyaddr((const char *) &clientaddr.sin_addr.s_addr,
                           sizeof(clientaddr.sin_addr.s_addr),
                           AF_INET);
        haddrp = inet_ntoa(clientaddr.sin_addr);
        printf("server connected to %s (%s)\n", hp->h_name, haddrp);

        echo(connfd);
        Close(connfd);
    }

    exit(0);
}
