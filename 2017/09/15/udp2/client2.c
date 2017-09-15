//
// Created by zhangrongxiang on 2017/9/15.
//
/*client.c*/

#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> /* netbd.h is needed for struct hostent =) */
#include <arpa/inet.h>

#define PORT 1234 /* Open Port on Remote Host */
#define MAXDATASIZE 100 /* Max number of bytes of data */

/*
 udp广播通信，执行时需要两个参数如下：
 ./client 192.168.1.255
 这样便会对192.168.1这个网段内所有开着./server的主机发送数据
 */
int main(int argc, char *argv[]) {

    int fd, numbytes; /* files descriptors */
    char recvbuf[MAXDATASIZE]; /* buf will store received text */
    char sendbuf[MAXDATASIZE];
    struct hostent *he; /* structure that will get information about remote host */
    struct sockaddr_in server, client; /* server's address information */
    int yes;
    FILE *file;

    if ((file = fopen("client.c", "r"))== NULL) {
        printf("open out.txt error....\n");
        exit(-1);
    }
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) { // calls socket()
        printf("socket() error\n");
        exit(1);
    }
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT); /* htons() is needed again */
    server.sin_addr.s_addr = inet_addr("192.168.33.11");
    socklen_t len;
    len = sizeof(struct sockaddr_in);
    while (fgets(sendbuf, 100, file)) {
        printf("%s", sendbuf);
        sendto(fd, sendbuf, strlen(sendbuf), 0, (struct sockaddr *) &server, len);
        if ((numbytes = recvfrom(fd, recvbuf, MAXDATASIZE, 0, (struct sockaddr *) &server, &len)) == -1) { /* calls recvfrom() */
            printf("recvfrom() error\n");
            break;
        }
        recvbuf[numbytes] = '\0';
    }
    fclose(file);
    close(fd); /* close fd */
    return 0;
}