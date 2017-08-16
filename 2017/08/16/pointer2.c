//
// Created by zhangrongxiang on 2017/8/16 14:50.
// Copyright (c) 2017 ZRC . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void one()
{
    char *ptr = NULL;
    char *buflist = NULL;
    buflist = (char *) malloc(1024);
    ptr =(char *)(*((unsigned long *)buflist));

    printf("----------------------------------\n");
    if(ptr == NULL){
        printf("error");
        exit(1);
    }
    else{
        printf("ptr != NULL");
    }
    for (int i = 0; i < 5; ++i) {
            ptr[i] =(char) i;
    }
//
    for (int i = 0; i < 5; ++i) {
        printf("%d\n",*(ptr++));
    }

}
int main()
{
    one();

}