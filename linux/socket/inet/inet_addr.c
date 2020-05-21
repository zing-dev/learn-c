//
// Created by zing on 5/21/2020.
//

#include <stdio.h>
#include <arpa/inet.h>

/* Convert Internet host address from numbers-and-dots notation in CP
   into binary data in network byte order.  */
int main(int argc, char *argv[]) {
    char *host = "192.168.0.1";
    struct in_addr addr;
    addr.s_addr = inet_addr(host);
    printf("addr.s_addr:%d\n", addr.s_addr);
    printf("host %s\n",inet_ntoa(addr));
    return 0;
}
