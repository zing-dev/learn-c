//
// Created by 张荣响 on 2017/8/7.
//


/*client.c*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#define MAXBUF 256
int main(int argc, char const *argv[])
{
    int s = 0;
    int n = 0;
    int reuse = 1;
    int port = 1994;
    struct sockaddr_in srv;
    char buf[MAXBUF] = {0};
//    printf("0 %s\n",argv[0]);
//    printf("1 %s\n",argv[1]);
//    printf("2 %s\n",argv[2]);
    if(strcmp(argv[1],"localhost") || argv[1] == NULL){
        argv[1] = "127.0.0.1";
    }
    /*解析参数*/
    if (argc != 2)
    {
        printf("Usage:%s ServerIP\n", argv[0]);
        return -1;
    }
    bzero(&srv, sizeof(srv));
    srv.sin_family = PF_INET;
    srv.sin_addr.s_addr = inet_addr(argv[1]);
    srv.sin_port = htons(port);
    /*创建 UDP 套节字*/
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s<0){
        perror("socket");
        return -1;
    }

    while(1){
        memset(buf, 0, MAXBUF);
        /*读取用户输入到buf中*/
        fgets(buf, MAXBUF, stdin);

        /*通过套节字 s 向服务器发送数据*/
        if ((n = sendto(s, buf, strlen(buf), 0, (struct sockaddr *) &srv, sizeof(struct sockaddr))) < 0)
        {
            perror("sendto");
            return -1;
        }else{
            printf("send to %s(port=%d) len %d:%s\n", argv[1], port, n, buf);
        }
    }
}