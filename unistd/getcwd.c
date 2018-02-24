//
// Created by zhangrongxiang on 2018/2/24 9:21
// File getcwd
//

#include <unistd.h>
#include <stdio.h>

int main() {
    char buf[64];
    char *rs = getcwd(buf, sizeof(buf));
    printf("%s\n", rs);//   /home/vagrant/devspace/learn-c/unistd
    printf("%s\n", buf);//  /home/vagrant/devspace/learn-c/unistd
    printf("%d\n", buf == rs);//1
    return 0;
}
