//
// Created by zhangrongxiang on 2018/3/25 22:30
// File constan5
//
//指针常量(指针本身是常量)
#include <stdio.h>

int main() {
    int i = 10;
    int *const p = &i;
    printf("%d\n", *p);//10
    //Error,因为p是const 指针，因此不能改变p指向的内容
    //p++;//error: increment of read-only variable ‘p’
    (*p)++;    //OK,指针是常量，指向的地址不可以变化,但是指向的地址所对应的内容可以变化
    printf("%d\n", *p);//11
    i = 9;//OK,仍然可以通过原来的声明修改值，
    return 0;
}