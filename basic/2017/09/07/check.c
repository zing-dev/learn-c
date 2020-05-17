//
// Created by zhang on 2017/9/7.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

static void usage() {
    printf("usage : ipconfig interface \n");
    exit(0);
}

int main(int argc, char **argv) {
    struct sockaddr_in *addr;
    struct ifreq ifr;
    char *name, *address;
    int sockfd;

    if (argc != 2) usage();
    else name = argv[1];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    strncpy(ifr.ifr_name, name, IFNAMSIZ - 1);

    if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1)
        perror("ioctl error"), exit(1);

    addr = (struct sockaddr_in *) &(ifr.ifr_addr);
    address = inet_ntoa(addr->sin_addr);
    printf("inet addr: %s \n", address);

    if (ioctl(sockfd, SIOCGIFBRDADDR, &ifr) == -1)
        perror("ioctl error"), exit(1);

    addr = (struct sockaddr_in *) &ifr.ifr_broadaddr;
    address = inet_ntoa(addr->sin_addr);
    printf("broad addr: %s \n", address);

    if (ioctl(sockfd, SIOCGIFNETMASK, &ifr) == -1)
        perror("ioctl error"), exit(1);
    addr = (struct sockaddr_in *) &ifr.ifr_addr;
    address = inet_ntoa(addr->sin_addr);
    printf("inet mask: %s \n", address);

    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == -1)
        perror("ioctl error"), exit(1);
    printf("ifr_hwaddr : %02x:%02x:%02x:%02x:%02x:%02x\n",
           (unsigned char) ifr.ifr_hwaddr.sa_data[0],
           (unsigned char) ifr.ifr_hwaddr.sa_data[1],
           (unsigned char) ifr.ifr_hwaddr.sa_data[2],
           (unsigned char) ifr.ifr_hwaddr.sa_data[3],
           (unsigned char) ifr.ifr_hwaddr.sa_data[4],
           (unsigned char) ifr.ifr_hwaddr.sa_data[5]);
    printf("\n");
    exit(0);
}