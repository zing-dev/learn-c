//
// Created by zing on 5/21/2020.
//


#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct in_addr addr = {};
    addr.s_addr = inet_addr("127.0.1.1");
    in_addr_t netof = inet_netof(addr);
    printf("%d\n",netof);
    return 0;
}
