//
// Created by zhangrongxiang on 2017/10/12 10:53
// File addr
//

#include <stdio.h>
#include <arpa/inet.h>

int main() {
    //32bit  int
    unsigned long addr = inet_addr("192.168.0.100");
    printf("addr = %ud\n", ntohl(addr));//转换成主机字节序

    struct in_addr ipaddr;
    ipaddr.s_addr = addr;
    printf("%s\n", inet_ntoa(ipaddr));//转成成点分十进制
    return 0;
}