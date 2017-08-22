//
// Created by zhangrongxiang on 2017/8/22 16:11.
// Copyright (c) 2017 ZRX . All rights reserved.
//
#include <stdio.h>
#define DEBUG 1
//可变参数不能省略，尽管可以传一个空参数进去。
#define LOG0(format, ...) printf(__VA_ARGS__)

#define LOG(format, ...) fprintf(stdout, format, ##__VA_ARGS__)
//如果token为空，“##”则不进行连接，所以允许省略可变参数。
#define LOG2(format, args...) fprintf(stdout, format, ##args)

#ifdef DEBUG
#define LOG3(format, ...) fprintf(stdout, ">>>>> " format " <<<<\n", ##__VA_ARGS__)
#else
#define LOG4(format, ...) fprintf(stdout, "---> " format " <---\n", ##__VA_ARGS__)
#endif

#ifdef DE
#define LOG5(format, ...) fprintf(stdout, "---> " format " <---\n", ##__VA_ARGS__)
#endif
int main()
{
    LOG0(NULL,"what","fuck");
    LOG("%s\n","Hello World");
    LOG("Hello World\n");

    LOG("Hello World\n",NULL);


    LOG2("%s\n","Hello World");
    LOG2("Hello World\n");

    LOG3("debug  --> %s","Hello World");

    LOG5("[my debug] %s","Hello World");
}