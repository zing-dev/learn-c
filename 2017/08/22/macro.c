//
// Created by zhangrongxiang on 2017/8/22 10:37.
// Copyright (c) 2017 ZRX . All rights reserved.
//

#include <stdio.h>

//语言符号字符串化(stringizing).  #X
#define TEST(x) printf("square of  " #x " is %d.\n",(x)*(x))
#define CAT(x,y) #x "-" #y
#define PRINT_CAT(x,y) "%s-%s\n",#x,#y

// ##运算符可以用于类函数宏的替换部分.##还可以用于类对象宏的替换部分.
// 这个运算符可以把两个语言符号组合成单个语言符号.
#define XNAME(n) x##n
#define INTI(n) int XNAME(n)
void main()
{
    int y = 4;
    TEST(y);
    TEST(6 - 3);
    TEST(y + 3);

    printf("%s\n",CAT(Hello,World));
    printf(PRINT_CAT(Hello,World));

    int XNAME(1) = 10;
    printf("%d\n",x1);

    INTI(5);
    x5 = 11;
    printf("%d\n",x5);
}

