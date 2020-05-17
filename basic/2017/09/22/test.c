//
// Created by zhangrongxiang on 2017/9/22 11:06
//

#include "test.h"
#include <stdio.h>

static int i = 1;/*声明为内部变量，只能用于test.c源文件*/
int j = 2;/*可以作为外部变量使用，在main文件中用到了*/

static void fun1(void)/*声明为内部函数，只能用在test.c源文件中*/
{
    printf("i+1 = %d, j+1 = %d\n", i + 1, j + 1);
}

void fun(void)/*可以用在其他文件中，用在main文件中*/
{
    printf("i = %d, j = %d\n", i, j);
    fun1();
}