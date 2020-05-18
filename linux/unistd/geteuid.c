//
// Created by zhangrongxiang on 2018/2/26 13:51
// File geteuid
//
#include <unistd.h>
#include <stdio.h>
//geteuid - get the effective user ID

int main() {
    uid_t id;
    id = geteuid();
    printf("%d\n", (int) id);
    // ./a.out 1000
    // sudo ./a.out 0
    return 0;
}