//
// Created by zhangrongxiang on 2017/10/9 17:25
// File inet_
//

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


/**
 * a --> string
 * n --> binary
 * @return
 */
int main() {
    struct in_addr addr1, addr2;
    long l1, l2;
    l1 = inet_addr("192.168.0.74");
    l2 = inet_addr("211.100.21.179");
    printf("l1 is %ld\n", l1);
    printf("l2 is %ld\n", l2);
    memcpy(&addr1, &l1, 4);
    memcpy(&addr2, &l2, 4);
//    192.168.0.74 : 192.168.0.74
//    inet_ntoa 函数转换网络字节排序的地址为标准的ASCII以点分开的地址
    printf("%s : %s\n", inet_ntoa(addr1), inet_ntoa(addr2)); //注意这一句的运行结果
//    192.168.0.74
    printf("%s\n", inet_ntoa(addr1));
//    211.100.21.179
    printf("%s\n", inet_ntoa(addr2));
    return 0;
}
