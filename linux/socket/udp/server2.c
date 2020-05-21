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
    int reuse = 1;
    int cli_len = sizeof(struct sockaddr);
    int port = 1994;
    char buf[MAX_BUF] = {0};
    struct sockaddr_in addr, cli;

    /*初始化本地监听端口信息*/
    bzero(&addr, sizeof(addr));
    addr.sin_family = PF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    //inet_aton("192.168.31.113", &addr.sin_addr);
    addr.sin_port = htons(port);

    /*创建UDP套节字*/
    s = socket(AF_INET, SOCK_DGRAM, PF_UNSPEC);
    if (s < 0) {
        perror("socket");
        return -1;
    }

    /*允许端口复用*/
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    /*绑定指定端口*/
    if (bind(s, (const struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        return -1;
    }

    while (1) {
        memset(buf, 0, MAX_BUF);
        /*从套节字s中读取数据*/
        n = recvfrom(s, buf, MAX_BUF, 0, (struct sockaddr *) &cli, (socklen_t *) &cli_len);
        if (n < 0) {
            perror("recvfrom");
            break;
        } else {
            printf("receive msg from %s(port=%d) len %d: %s\n", inet_ntoa(cli.sin_addr), port, n, buf);
        }
    }
    return 0;
}