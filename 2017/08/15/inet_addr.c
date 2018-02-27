#include<stdio.h>
#include<arpa/inet.h>
#include <stdint.h>

int main() {
    //1006741696
    printf("%d\n", inet_addr("192.168.1.60"));
    printf("%u\n", inet_addr("192.168.1.60"));
    in_addr_t addr = inet_addr("192.168.33.13");
    printf("%d\n",(int) sizeof(in_addr_t));//4
    printf("%d\n",(int) sizeof(uint32_t));//4
    return 0;
}

