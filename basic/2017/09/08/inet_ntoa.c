//
// Created by zhang on 2017/9/8.
//

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


/**
 *
 * 函数声明：char *inet_ntoa (struct in_addr);
 * 返回点分十进制的字符串在静态内存中的指针。
 *　所在头文件：<arpa/inet.h>
 *　//end linux 下
 *　函数功能：将网络地址转换成“.”点隔的字符串格式
 *  现在我们很幸运，因为我们有很多的函数来方便地操作 IP 地址。没有必要用手工计算它们，也没有必要用"<<"操作来储存成长整字型。首先，假设你已经有了一个sockaddr_in结构体ina，你有一个IP地址"132.241.5.10"要储存在其中，你就要用到函数inet_addr(),将IP地址从 点数格式转换成无符号长整型。使用方法如下：
 * ina.sin_addr.s_addr = inet_addr("132.241.5.10");
 * 注意，inet_addr()返回的地址已经是网络字节格式，所以你无需再调用 函数htonl()。
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    struct in_addr addr1, addr2;
    ulong l1, l2;
    l1 = inet_addr("192.168.0.74");
    l2 = inet_addr("211.100.21.179");
    memcpy(&addr1, &l1, 4);
    memcpy(&addr2, &l2, 4);
    printf("%s : %s\n", inet_ntoa(addr1), inet_ntoa(addr2)); //注意这一句的运行结果
    printf("%s\n", inet_ntoa(addr1));
    printf("%s\n", inet_ntoa(addr2));
    return 0;
}

