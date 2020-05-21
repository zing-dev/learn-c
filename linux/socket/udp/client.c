//
// Created by zing on 5/21/2020.
//

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_BUF 256

int main(int argc, char const *argv[]) {
    int s = 0;
    int n = 0;
    int port = 1995;
    struct sockaddr_in srv;
    char *addr = "127.0.0.1";
    char buf[MAX_BUF] = {0};

    if (argc == 2) {
        addr = (char *) argv[1];
    }

    bzero(&srv, sizeof(srv));
    srv.sin_family = PF_INET;
    srv.sin_addr.s_addr = inet_addr(addr);
    srv.sin_port = htons(port);
    s = socket(AF_INET, SOCK_DGRAM, PF_UNSPEC);
    if (s < 0) {
        perror("socket");
        return -1;
    }

    while (1) {
        memset(buf, 0, MAX_BUF);
        /*读取用户输入到buf中*/
        fgets(buf, MAX_BUF, stdin);
        /*通过套节字 s 向服务器发送数据*/
        if ((n = sendto(s, buf, strlen(buf), 0, (struct sockaddr *) &srv, sizeof(struct sockaddr))) < 0) {
            perror("sendto");
            return -1;
        } else {
            printf("send to %s(port=%d) len %d:%s\n", addr, port, n, buf);
        }
    }
}
