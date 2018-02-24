//
// Created by zhangrongxiang on 2018/2/24 9:20
// File chdir
//

#include <unistd.h>
#include <stdio.h>

int main() {
    char path[64];
    getcwd(path, sizeof(path));
    printf("now path is %s\n", path);//now path is /home/vagrant/devspace/learn-c/unistd
    chdir("../");
    getcwd(path, sizeof(path));
    printf("now path is %s\n", path);//now path is /home/vagrant/devspace/learn-c
    return 0;
}