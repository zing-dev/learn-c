//
// Created by zing on 5/26/2020.
//
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include <errno.h>

#define LEN 1024
const int PORT = 1234;
struct sockaddr_in client;
struct sockaddr_in local;
int listenSock;
int linkSock = -1;
int fds[64];
socklen_t size_client = sizeof(client);

int ListenSock() {
    listenSock = socket(AF_INET, SOCK_STREAM, 0);
    if (listenSock < 0) {
        perror("socket");
        return errno;
    }

    local.sin_family = AF_INET;
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_port = htons(PORT);

    if (bind(listenSock, (struct sockaddr *) &local, sizeof(local)) < 0) {
        perror("bind");
        return errno;
    }

    if (listen(listenSock, 5) < 0) {
        perror("listen");
        return errno;
    }
    return listenSock;
}

int main() {
    listenSock = ListenSock();       //进入监听状态
    char buf[LEN];
    memset(buf, '\0', LEN);
    int loop = 100;
    while (1) {
        fd_set reads, writes;
        int fds_max;       //fds中最大的一个文件描述符
        int i = 0;
        int fds_num = sizeof(fds) / sizeof(fds[0]);
        for (; i < fds_num; i++) {
            fds[i] = -1;
        }

        fds[0] = listenSock;
        fds_max = fds[0];
        struct timeval times;
        loop--;
        while (1) {
            FD_ZERO(&reads);                 //每次循环都要初始化，因为reads与writes即是是输入型参数，也是输出型参数
            FD_ZERO(&writes);
            FD_SET(listenSock, &reads);     //listenSock只关心读事件
            times.tv_sec = 10;
            times.tv_usec = 0;
            struct timeval timeval;
            for (i = 1; i < fds_num; i++) {
                //在select之前把所有的文件描述符都设置读事件
                if (fds[i] > 0) {
                    FD_SET(fds[i], &reads);  //所有的socket都要关心读事件
                    FD_SET(fds[i], &writes);  //所有的socket都要关心读事件
                    if (fds[i] > fds_max) {
                        fds_max = fds[i];
                    }
                }
            }
            //select函数返回已就绪的文件描述符的个数
            int ret = select(fds_max + 1, &reads, &writes, NULL, &timeval);
            if (ret == 0) {
                printf("time out....!\n");
                break;
            } else if (ret == -1) {
                perror("select");
                break;
            } else {
                for (i = 0; i < fds_num; i++) {
                    if (FD_ISSET(fds[i], &reads)) {
                        if (fds[i] == listenSock) {
                            linkSock = accept(listenSock, (struct sockaddr *) &client, &size_client);
                            if (linkSock < 0) {
                                perror("accept");
                                continue;
                            }
                            printf("a new connect is create...... the fds is %d\n", linkSock);
                            for (i = 0; i < fds_max; i++) {
                                if (fds[i] < 0) {
                                    fds[i] = linkSock;
                                    FD_SET(linkSock, &reads);
                                    FD_SET(linkSock, &writes);
                                    break;
                                }
                            }

                            if (i == fds_max - 1) {
                                printf("文件描述符集已满，请关闭一些链接，以保证系统能正常工作！\n");
                            }
                        } else {
                            memset(buf, '\0', LEN);
                            ret = read(fds[i], buf, LEN);
                            if (ret < 0) {
                                perror("read");
                                continue;
                            } else if (ret == 0) {
                                printf("a connect is closed...... the fds is %d\n", fds[i]);
                                close(fds[i]);
                                fds[i] = -1;
                                continue;
                            } else {
                                buf[ret] = '\0';
                                printf("client%d# %s\n", fds[i], buf);
                            }
                            if (write(fds[i], buf, strlen(buf)) < 0) {
                                perror("write");
                                continue;
                            }
                        }
                    }
                }
            }
        }
        if (loop == 0) {
            break;
        }
    }
    return errno;
}