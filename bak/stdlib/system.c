//
// Created by zhangrongxiang on 2018/2/27 13:34
// File system
//

#include <stdlib.h>
#include <stdio.h>

int main(){
    int r = system("ls -al .");
    if(r == 0){
        printf("exec success!\n");
    }
    return 0;
}