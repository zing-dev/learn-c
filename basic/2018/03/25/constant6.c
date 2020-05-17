//
// Created by zhangrongxiang on 2018/3/25 22:38
// File constant6
//
#include <stdio.h>

int main() {
    int i = 10;
    const int *const p = &i;
    printf("%d\n", *p);//10
    //p++;//error: increment of read-only variable ‘p’
    //(*p)++;//increment of read-only location ‘*p’
    i++;//OK,仍然可以通过原来的声明修改值
    printf("%d\n", *p);//11
    return 0;
}