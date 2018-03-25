//
// Created by zhangrongxiang on 2018/3/25 22:16
// File constant4
//
#include <stdio.h>

// 常量指针(被指向的对象是常量)
int main() {
    int i = 10;
    int i2 = 11;
    const int *p = &i;
    printf("%d\n", *p);//10
    i = 9; //OK,仍然可以通过原来的声明修改值，
    //Error,*p是const int的，不可修改，即常量指针不可修改其指向地址
    //*p = 11;  //error: assignment of read-only location ‘*p’
    p = &i2;//OK,指针还可以指向别处，因为指针只是个变量，可以随意指向；
    printf("%d\n", *p);//11
    return 0;
}
