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
#define PORT 1994

int main(int argc, char *argv[]) {
    int socketfd = 0;
    int reuse = 0;
    int recv = 0;
    char buf[MAXBUF] = {0};
    char msg[MAXBUF] = {0};

    struct sockaddr_in server, client;
    int sock_len = sizeof(struct sockaddr);

    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd < 0) {
        perror("create socket error ... ");
        return -1;
    }

    setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if (bind(socketfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind error ...");
        return -1;
    }
    printf("udp server start [%d][0.0.0.0][%d] -------> \n", socketfd, PORT);
    while ((recvfrom(socketfd, msg, sizeof(MAXBUF - 1), 0, (struct sockaddr *) &client, &sock_len)) > 0) {
//        msg[MAXBUF] = '\0';
        printf("read [%s:%d] mag-->%s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port), msg);
        //这里发送信息过去, 也可以事先connect这里就不绑定了
        int send = sendto(socketfd, msg, strlen(msg), 0, (struct sockaddr *) &client, sock_len);
        if (send > 0) {
            printf("send success ......\n");
        } else {
            perror("send error ...\n");
            break;
        }
    }
/**
    while (1) {
        memset(buf, 0, MAXBUF);
        recv = recvfrom(
                socketfd,
                buf,
                MAXBUF,
                0,
                (struct sockaddr *) &client,
                &sock_len
        );

        if(recv < 0){
            perror("recvfrom error ... \n");
            break;
        } else{
            printf("receive msg from %s(port=%d) len %d: %s\n",inet_ntoa(client.sin_addr), PORT, recv, buf);
        }
    }
    */
    return 0;
}