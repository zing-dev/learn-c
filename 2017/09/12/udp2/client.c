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
//#define ADDR "127.0.0.1"

int main() {
    struct sockaddr_in server;
    int socketfd = 0;
    char *addr = "127.0.0.1";
    char buf[MAXBUF] = {0};
    char msg[MAXBUF] = {0};
    int sock_len = sizeof(struct sockaddr);

    bzero(&server, sizeof(server));

    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr(addr);
    server.sin_port = htons(PORT);

    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd < 0) {
        printf("create socket error ... ");
        return -1;
    }
    printf("udp server start [%d][0.0.0.0][%d] -------> \n", socketfd, PORT);


    /**
    memset(buf, 0, MAXBUF);
    fgets(buf, MAXBUF, stdin);
    int send = sendto(socketfd, buf, strlen(buf), 0,
                      (struct sockaddr *) &server,
                      sizeof(struct sockaddr)
    );
    if(send < 0){
        perror("sendto error ....");
    } else{
        printf("send to %s(port=%d) len %d:%s\n",
               addr,PORT, send, buf);
    }
     */
//    if (bind(socketfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
//        perror("bind error ....");
//        return -1;
//    }
    /**
    while ((recvfrom(socketfd, msg, sizeof(MAXBUF - 1), 0, (struct sockaddr *) &server, &sock_len)) > 0) {
//        msg[MAXBUF] = '\0';
        printf("read [%s:%d] mag-->%s\n", inet_ntoa(server.sin_addr), ntohs(server.sin_port), msg);
        //这里发送信息过去, 也可以事先connect这里就不绑定了
        int send = sendto(socketfd, msg, strlen(msg), 0, (struct sockaddr *) &server, sock_len);
        if (send > 0) {
            printf("send success ......\n");
        } else {
            perror("send error ...\n");
            break;
        }
    }
     */
    while (1){
        memset(buf, 0, MAXBUF);
        fgets(buf, MAXBUF, stdin);
        int send = sendto(socketfd, buf, strlen(buf), 0,
               (struct sockaddr *) &server,
               sizeof(struct sockaddr)
        );

        if(send < 0){
            perror("sendto error ....");
            break;
        } else{
            printf("send to %s(port=%d) len %d:%s\n",
                   addr, PORT, send, buf);
        }
    }
    return 0;
}