//
// Created by zhangrongxiang on 2017/8/23 10:36.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdio.h>

extern void myprint(const char *format, ...) __attribute__((format(printf, 1, 2)));
void test()
{
    myprint("i=%d\n", 6);
    myprint("i=%s\n", 6);
    myprint("i=%s\n", "abc");
    myprint("%s,%d,%d\n", 1, 2);
}
int main()
{
    test();
    return 0;
}