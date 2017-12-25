//
// Created by zhangrongxiang on 2017/8/22 9:15.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdio.h>


//  关键字typeof用于获取表达式的数据类型。
#define array(type, size) typeof(type [size])

int func(int num) {
    return num + 5;
}

int main(void) {
    typeof(func) *pfunc = func; //等价于int (*pfunc)(int) = func;
    printf("pfunc(10) = %d\n", (*pfunc)(10));

    array(char,) charray = "hello world!"; //等价于char charray[] = "hello world!";
    typeof(char * ) charptr = charray; //等价于char *charptr = charray;
    typeof(int * ) charptr2 = (int *) charray; //等价于int *charptr = charray;

    printf("%s\n", charptr);
    printf("%s\n", charptr2);

    char *chptr01 = "WTF";
    printf("%s\n", chptr01);
    typeof(*chptr01) ch = 'W'; //等价于char ch;
    printf("%c\n", ch);
    typeof(chptr01) ch2; //等价于char* ch2;
    ch2 = "hello world";
    printf("%s\n", ch2);
    typeof(ch) *chptr02; //等价于char *chptr02;
    typeof(chptr01) chparray[5]; //等价于char *chparray[5];


    return 0;
}