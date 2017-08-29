//
// Created by zhangrongxiang on 2017/8/29 16:04.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int result = system("ls");
    if(result == -1){
        printf("error.....");
    }
    else{
        printf("success....");
    }
    char *ls;
    exec("ls",ls);
    printf("%s\n",ls);
    return 0;
}