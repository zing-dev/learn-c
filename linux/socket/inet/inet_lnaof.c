//
// Created by zing on 5/21/2020.
//

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>


#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*
 * Return the local network address portion of an
 * internet address; handles class a/b/c network
 * number formats.
 */
in_addr_t
inet_lnaof(struct in_addr in) {
    uint32_t i = ntohl(in.s_addr);

    if (IN_CLASSA(i))
        return ((i) & IN_CLASSA_HOST);
    else if (IN_CLASSB(i))
        return ((i) & IN_CLASSB_HOST);
    else
        return ((i) & IN_CLASSC_HOST);
}


/* Return the local host address part of the Internet address in IN.  */
int main(int argc, char *argv[]) {
    struct in_addr addr;
    memset(&addr, 0, sizeof(struct in_addr));
    addr.s_addr = inet_addr("192.168.11.112");
    in_addr_t i = inet_lnaof(addr);
    printf("%d\n", addr.s_addr);
    printf("%d\n", i);
    printf("%s\n", inet_ntoa(addr));
    return 0;
}
