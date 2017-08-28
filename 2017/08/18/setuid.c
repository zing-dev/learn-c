//
// Created by 张荣响 on 2017/8/18.
//

//setuid函数设置实际用户ID和有效用户ID。
//在Linux中， setuid(uid)函数的执行步骤为:
// (1)如果由普通用户调用,将当前进程的有效ID设置为uid.
// (2)如果由有效用户ID符为0的进程调用,则将真实,有效和已保存用户ID都设置为uid.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    if (!setuid(1234)) {
        printf("setuid successfully!\n");
    }
    else {
        printf("setuid error!\n");
        perror("setuid\n");
    }

    privlog();

    return 0;
}