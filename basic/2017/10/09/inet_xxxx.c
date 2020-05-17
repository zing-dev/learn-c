//
// Created by zhangrongxiang on 2017/10/9 16:53
// File inet_xxxx
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
//
/**
 * 字符串形式的IP和整数形式的IP之间转换
 */
//http://blog.csdn.net/ithomer/article/details/6100734

//int inet_aton(const char *cp, struct in_addr *inp);
//in_addr_t inet_addr(const char *cp);
//in_addr_t inet_network(const char *cp);
//int inet_pton(int af, const char *src, void *dst);
//const char *inet_ntop(int af, const void *src, char *dst, socklen_t cnt);

int main() {

/**
 *
 * IP 字符串 -->>>>  网络字节流
 * inet_addr、inet_network、inet_aton
 */
    char ip[] = "192.168.0.74";
    long r1, r2, r3;  //long
    struct in_addr addr;

    r1 = inet_addr(ip); //返回网络字节序
    if (-1 == r1) {
        printf("inet_addr return -1\n");
    } else {
        printf("inet_addr ip: %ld\n", r1);
    }

    r2 = inet_network(ip);    //返回主机字节序
    if (-1 == r2) {
        printf("inet_addr return -1\n");
    } else {
        printf("inet_network ip: %ld\n", r2);
        printf("inet_network ip: %ld\n", ntohl(r2));   //ntohl: 主机字节序 ——> 网络字节序
    }

    r3 = inet_aton(ip, &addr);  //返回网络字节序
    if (0 == r3) {
        printf("inet_aton return -1\n");
    } else {
        printf("inet_aton ip: %ld\n", addr.s_addr);
    }

/*****  批量注释的一种方法  *****/
#if 0
    r3 = inet_aton(ip, addr);
    if(0 == r3){
        printf("inet_aton return -1\n");
    }else{
        printf("inet_aton ip: %ld\n", ntohl(addr.s_addr));
    }
#endif

    /**
     * IP 字符串 <-------> 网络字节流
     * inet_addr、inet_aton、inet_ntoa
     */

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
