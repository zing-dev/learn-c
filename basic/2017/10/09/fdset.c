//
// Created by zhangrongxiang on 2017/10/9 11:37
// File fdset
//

#include <stdio.h>
#include <sys/types.h>

int main() {
    /*
     * FD_SET(int fd, fd_set *fdset);       //将fd加入set集合
     * FD_CLR(int fd, fd_set *fdset);       //将fd从set集合中清除
     * FD_ISSET(int fd, fd_set *fdset);     //检测fd是否在set集合中，不在则返回0
     * FD_ZERO(fd_set *fdset);              //将set清零使集合中不含任何fd
     */
    fd_set fdset;
    FD_ZERO(&fdset);
    FD_SET(1, &fdset);
    FD_SET(2, &fdset);
    FD_SET(3, &fdset);
    FD_SET(7, &fdset);
    int isset = FD_ISSET(3, &fdset);
    printf("isset = %d\n", isset); //1
    printf("fdset sizeof is %ld\n", sizeof(fdset));
    FD_CLR(3, &fdset);
    printf("fdset sizeof is %ld\n", sizeof(fdset));
    isset = FD_ISSET(3, &fdset); //0
    printf("isset = %d\n", isset);
    return 0;
}