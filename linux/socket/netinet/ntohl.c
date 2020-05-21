//
// Created by zing on 5/21/2020.
//

#include <netinet/in.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    //  TEST (0x67452301, 0x01234567, htonl);
    uint32_t i = ntohl(0x01234567);
    printf("%.2x\n",i);
    i = ntohl(0x67452301);
    printf("%.2x\n",i);
    i = htonl(0x67452301);
    printf("%.2x\n",i);
    i = htonl(0x01234567);
    printf("%.2x\n",i);
    printf("%.2x\n",0x01234567 + 0x67452301);
    printf("%d\n",0x01234567 + 0x67452301);

    printf("%d\n",BYTE_ORDER == LITTLE_ENDIAN);
    printf("%d\n",BYTE_ORDER);
    printf("%d\n",LITTLE_ENDIAN);
    printf("%d\n",BIG_ENDIAN);
    printf("%d\n",PDP_ENDIAN);
    printf("%x\n",htobe32(1000));
    printf("%x\n",be32toh(1000));
    printf("%x\n",be32toh(0xe8030000));
    printf("%x\n",htobe32(0xe8030000));
    return 0;
}
