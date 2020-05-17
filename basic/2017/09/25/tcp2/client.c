//
// Created by zhangrongxiang on 2017/9/25 13:58
//

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

struct info {
    char name[10];
    char buf[100];
};

//利用多线程接收发来的信息，可以在任何时候接收信息，包括发信息的时候
void *getmssage(void *p) {
    int *sockfd = (int *) p;
    struct info from;
    while (recv(*sockfd, &from, sizeof(from), 0) > 0) {
        printf("%s说:%s\n", from.name, from.buf);
        memset(from.name, 0, sizeof(from.name));
        memset(from.buf, 0, sizeof(from.buf));
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) perror("socket"), exit(-1);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2222);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (res == -1) perror("connect"), exit(-1);

    struct info in;
    printf("请输入用户名：\n");
    scanf("%s", in.name);
    //getchar(); //此时必须要用getchar 因为第 43 行用的是gets接收数据， 38行的scanf函数接收数据的时候碰到 \n就结束了，下面的gets 就会把缓存区的 \n 给接收到， 如果下面用 scanf 接收数据的话，此时就不需要用 getchar了， 因为 scanf 在第一个字符碰到 \n的时候会直接把 \n 给忽略掉
    pthread_t pid;
    pthread_create(&pid, 0, getmssage, (void *) &sockfd);
    while (1) {
        scanf("%s", in.buf);
        printf("buf is %s\n", in.buf);
//        gets(in.buf);
        if (!strcmp(in.buf, "bye")) {
            strcpy(in.buf, "退出登陆");
            send(sockfd, &in, sizeof(in), 0);
            exit(0);
        }
        if (send(sockfd, &in, sizeof(in), 0) == -1) perror("send"), exit(-1);
        memset(in.buf, 0, strlen(in.buf));
    }
}