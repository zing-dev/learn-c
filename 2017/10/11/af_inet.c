//
// Created by zhangrongxiang on 2017/10/10 13:29
// File af_inet
//

#include <stdio.h>
#include <arpa/inet.h>

int main(){

    // 网络地址族
    //Address Family
    //AF_INET 2
    printf("%d\n",AF_INET);

    //Protocol Family
    //PF_INET 2
    printf("%d\n",PF_INET);
    //AF_INET6 10
    printf("%d\n",AF_INET6);
    // 10
    printf("%d\n",PF_INET6);

//    本地地址族 AF_UNIX或AF_LOCAL
    // 1
    printf("AF_UNIX %d\n",AF_UNIX);
    // 1
    printf("AF_LOCAL %d\n",AF_LOCAL);

//    红外地址类：AF_IRDA：
    // 23
    printf("AF_IRDA %d\n",AF_IRDA);
    return 0;
}