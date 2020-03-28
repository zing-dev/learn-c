//
// Created by zhangrongxiang on 2018/2/26 13:54
// File getgid
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
//getgid - get the real group ID

int main() {
    gid_t id;
    id = getgid();
    printf("%d\n", (int) id);
    // ./a.out 1000
    // sudo ./a.out 1000
    return 0;
}