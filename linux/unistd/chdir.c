//
// Created by zhangrongxiang on 2018/2/24 9:20
// File chdir
//

#include <unistd.h>
#include <stdio.h>

int main() {
    char path[128] = {};
    getcwd(path, sizeof(path));
    printf("now path is %s\n", path);// /mnt/c/Users/zing/workspace/c/learn-c/cmake-build-debug/linux/unistd
    chdir("../");
    getcwd(path, sizeof(path));
    printf("now path is %s\n", path);// /mnt/c/Users/zing/workspace/c/learn-c/cmake-build-debug/linux
    return 0;
}