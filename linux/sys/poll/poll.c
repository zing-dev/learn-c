//
// Created by zing on 5/27/2020.
//

#include <poll.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <strings.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

char *now() {
    char *example = "2020-05-27 12:12:12";
    char *str = (char *) malloc(sizeof(char) * (strlen(example) + 1));
    struct tm info;
    time_t now;
    time(&now);
    info = *localtime(&now);
    strftime(str, strlen(example) + 1, "%Y-%m-%d %H:%M:%S", &info);
    return str;
}

int poll1() {
    struct pollfd fds[1];
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    while (1) {
        int ret = poll(fds, 1, 100);
        if (ret == -1) {
            perror("poll");
            return errno;
        }
        if (fds[0].revents & POLLIN) {
            char buf[32];
            bzero(buf, sizeof(buf));
            ret = read(fds[0].fd, buf, sizeof(buf));
            if (ret == -1) {
                perror("read");
                return errno;
            }
            printf("read from stdin ==> %s\n", buf);
        }
    }
}

int poll2() {
    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    inet_pton(AF_INET, "192.168.0.111", &server.sin_addr);
    server.sin_port = htons(1234);

    int fd = socket(AF_INET, SOCK_STREAM, PF_UNSPEC);
    if (fd == -1) {
        perror("socket");
        return errno;
    }
    printf("%s socket start success\n",now());
    if (bind(fd, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("bind error: ");
        return errno;
    }
    printf("%s bind start success\n",now());

    if (listen(fd, 10) == -1) {
        perror("listen");
        return errno;
    }
    printf("%s listen start success\n",now());

    struct pollfd fds[10];
    fds[0].fd = fd;
    fds[0].events = POLLIN;
    for (int i = 1; i < 10; i++) {
        fds[i].fd = -1;
        fds[i].events = POLLIN;
    }

    while (1) {
        int ret = poll(fds, 10, 100);
        if (ret == -1) {
            perror("poll");
            break;
        }
        if (ret > 0) {
            if (fds[0].revents & POLLIN) {
                struct sockaddr_in client;
                socklen_t client_len = sizeof(client);
                int conn = accept(fd, (struct sockaddr *) &client, &client_len);
                if (conn == -1) {
                    perror("accept");
                    continue;
                }
                printf("%s accept a new client#%d:  <%s:%d>\n", now(), conn, inet_ntoa(client.sin_addr),
                       client.sin_port);
                int max = 0;
                for (int i = 1; i < 10; i++) {
                    max++;
                    if (fds[i].fd == -1) {
                        fds[i].fd = conn;
                        break;
                    }
                }
                if (max == 10) {
                    printf("too many clients.\n");
                }
            }

            for (int i = 1; i < 10; i++) {
                if (fds[i].revents & POLLIN) {
                    char buf[64];
                    bzero(buf, sizeof(buf));
                    ssize_t num = read(fds[i].fd, buf, sizeof(buf));
                    if (num == -1) {
                        perror("read");
                        break;
                    }
                    if (num > 0) {
                        printf("%s read from client#%d:\n\t\t%s\n", now(), fds[i].fd, buf);
                        write(fds[i].fd, buf, strlen(buf) + 1);
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    //printf("%s\n", now());
    //poll1();
    poll2();
    return 0;
}