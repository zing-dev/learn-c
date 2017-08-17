// Created by zhangrongxiang on 2017/8/17 9:38.
// Copyright (c) 2017 ZRX . All rights reserved.

#include <stdio.h>
int main() {
    char c = 'A';
    char *pc = &c;
    char
    /* 一维char类型指针数组*/*p[3],
    /*二维char类型指针数组*/*p1[3][3],
    /*一维char*数组*/**p2[3],
    /*存着指向char *类型的指针二维数组*/
        **p3[3][3],
    /*只向存着char类型的指针的一维数组的指针*/
        *(*p4)[3], (**p5)[3], (**p6)[3][3], (*(*p7))[3];

    p[1] = pc;
    printf("*pc is %c\n", *pc);
    printf("*p[1] is %c\n", *p[1]);
    printf("**(p + 1) is %c\n", **(p + 1));
    //*p1[3][3]
    p1[0][0] = pc;
    printf("*p1[0][0] is %c\n", *p1[0][0]);
    printf("**p1[0] is %c\n", **p1[0]);
    printf("***p1 is %c\n", ***p1);
    // **p2[3]
    p2[0] = &pc;
    printf("*p2[0][0] is %c\n", *p2[0][0]);
    printf("**p2[0] is %c\n", **p2[0]);
    printf("***p2 is %c\n", ***p2);
    //**p3[3][3]
    p3[0][0] = &pc;
    printf("*p3[0][0][0] is %c\n", *p3[0][0][0] );
    printf("**p3[0][0] is %c\n", **p3[0][0]);
    printf("***p3[0] is %c\n", ***p3[0]);
    printf("****p3[0] is %c\n", ****p3);
    //char *(*p4)[3]
//    (*p4)[0]=pc;
    (*p4)[0] = pc;
//    printf("%d\n",*(*p4)[0]);

//    (**p5)[0] = c;
//    (**p6)[0][0] = c;
//    (**p7)[0] = c;
}
