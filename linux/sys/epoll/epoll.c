//
// Created by zing on 5/28/2020.
//

#include <sys/epoll.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_EVENTS 10

void do_use_fd(int fd);


void setnonblocking(int sock);


int main() {

    struct epoll_event ev, events[MAX_EVENTS];
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    int listen_sock, conn_sock, nfds, epollfd;

    listen_sock = socket(AF_INET, SOCK_STREAM, PF_UNSPEC);
    if (listen_sock == -1) {
        perror("socket");
        return errno;
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(1122);
    server.sin_addr.s_addr = inet_addr("192.168.0.111");
    if (bind(listen_sock, (const struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("bind");
        return errno;
    }

    if (listen(listen_sock, MAX_EVENTS) == -1) {
        perror("listen");
        return errno;
    }

    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
        perror("epoll_ctl: listen_sock");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            break;
        }

        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == listen_sock) {
                bzero(&client, sizeof(client));
                conn_sock = accept(listen_sock, (struct sockaddr *) &client, &client_len);
                if (conn_sock == -1) {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                printf("new client %s:%d connected\n", inet_ntoa(client.sin_addr), client.sin_port);
                setnonblocking(conn_sock);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
                    perror("epoll_ctl: conn_sock");
                    exit(EXIT_FAILURE);
                }
            } else {
                do_use_fd(events[n].data.fd);
            }
        }
    }
    close(listen_sock);
    return 0;
}

void setnonblocking(int sock) {

}

void do_use_fd(int fd) {
    char buf[64];
    bzero(buf, sizeof(buf));
    ssize_t i = read(fd, buf, sizeof(buf));
    if (i == -1) {
        perror("read");
        return;
    }
    if (i > 0) {
        printf("read from client#%d%s\n", fd, buf);
    }
}
