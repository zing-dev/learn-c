//
// Created by zhangrongxiang on 2018/2/27 14:59
// File inet_aton
//

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main() {
//    int inet_aton(const char *cp, struct in_addr *inp);
    struct in_addr addr;
    char *ip = "127.0.0.1";
    if (inet_aton(ip, &addr) == 0) {
        fprintf(stderr, "Invalid address\n");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", inet_ntoa(addr));
    exit(EXIT_SUCCESS);
}