//
// Created by zing on 5/21/2020.
//


#include <netinet/in.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    uint32_t i = htonl(0x12345678);
    printf("%x",i); //78563412
    return 0;
}
