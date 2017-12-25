//
// Created by zhangrongxiang on 2017/8/24 14:36.
// Copyright (c) 2017 ZRX . All rights reserved.
//
#include <stdio.h>
#include <string.h>

int main() {
    char destination[] = "********************"; // destination串为: "********************0"
    const char *source = "-----";                // source串为:      "-----0"

    /**
     * C/C++中的strncpy()函数功能为将第source串的前n个字符拷贝到destination串，原型为：
     * 1、num<source串的长度（包含最后的'\0'字符）：
     * 那么该函数将会拷贝source的前num个字符到destination串中（不会自动为destination串加上结尾的'\0'字符）；
     * 2、num=source串的长度（包含最后的'\0'字符）：
     * 那么该函数将会拷贝source的全部字符到destination串中（包括source串结尾的'\0'字符）；
     * 3、num>source串的长度（包含最后的'\0'字符）：
     * 那么该函数将会拷贝source的全部字符到destination串中（包括source串结尾的'\0'字符），
     * 并且在destination串的结尾继续加上'\0'字符，直到拷贝的字符总个数等于num为止。
     */

//    strncpy(destination, source, 5 );
    //-----***************
//    destination串为: "-----***************0"
//    printf("%s\n",destination);

//    strncpy( destination, source, 6 );
//    -----
//    destination串为: "-----0**************0"
//    printf("%s\n",destination);

    strncpy(destination, source, 10);
//    destination串为: "-----00000**********0"
    printf("%s\n", destination);

}