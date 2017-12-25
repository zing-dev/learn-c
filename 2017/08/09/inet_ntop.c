//
// Created by 张荣响 on 2017/8/9.
//


#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    struct in_addr inAddr;
    uint32_t addr;
    char dst[8192];

    if (argc != 2) {
        fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
        exit(0);
    }
    sscanf(argv[1], "%x", &addr);

    inAddr.s_addr = htonl(addr);
    if (!inet_ntop(AF_INET, &inAddr, dst, 8192)) {
        fprintf(stderr, "%s: %s\n", "error", strerror(-1));
        exit(0);
    }
    printf("%s\n", dst);
    return 0;
}