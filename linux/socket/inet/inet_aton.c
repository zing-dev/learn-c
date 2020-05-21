//
// Created by zing on 5/21/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

/* Convert Internet host address from numbers-and-dots notation in CP
   into binary data and store the result in the structure INP.  */
int main() {
    struct in_addr addr;
    char *ip = "127.0.0.1";
    if (inet_aton(ip, &addr) == 0) {
        fprintf(stderr, "Invalid address\n");
        exit(EXIT_FAILURE);
    }
    //0000 ‭0001 0000 0000 0000 0000 0111 1111‬
    //        1          0        0       127
    printf("%d\n", addr.s_addr);//16777343
    printf("%s\n", inet_ntoa(addr));
    for (int i = 0; i < 4; i++) {
        //7f 00 00 01
        printf("%.2x ", ((unsigned char *) &addr.s_addr)[i]);
    }
    printf("%.2x\n", 127);
    exit(EXIT_SUCCESS);
}