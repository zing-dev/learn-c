//
// Created by zhangrongxiang on 2018/2/26 13:48
// File getegid
//

//getegid - get the effective group ID

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    gid_t id;
    id = getegid();
    printf("%d\n", (int) id);//1000
    return 0;
}