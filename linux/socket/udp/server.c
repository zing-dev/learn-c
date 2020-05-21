//
// Created by zing on 5/21/2020.
//


#include <sys/socket.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    struct sockaddr_in server = {}, client = {};
    bzero(&server, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1995);

    int fd = socket(AF_INET, SOCK_DGRAM, PF_UNSPEC);
    if (fd == -1) {
        perror("socket");
        return -1;
    }
    int reuse = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if (bind(fd, (const struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("bind");
        return -1;
    }

    int client_len = sizeof(struct sockaddr);
    while (1) {
        char buf[128] = {};
        printf("等待接受来自客户端发送数据...\n");
        if (recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *) &client, (socklen_t *) &client_len) == -1) {
            perror("recvfrom");
            break;
        }
        printf("receive from %s : %s\n", inet_ntoa(client.sin_addr), buf);
        if (sendto(fd, buf, sizeof(buf), 0, (struct sockaddr *) &client, sizeof(server)) == -1) {
            perror("sendto");
            break;
        }
    }
    close(fd);
    return 0;
}
