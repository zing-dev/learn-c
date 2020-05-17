#include <stdio.h>

//
// Created by zhangrongxiang on 2018/1/2 17:20
// File 1
//
int main() {
//    [行数][列数]
    int m[][3] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
    int arr[][3] = {};
    int i, j, k = 2;
    for (i = 0; i < 3; i++) {
        //二重数组，输出地址
        printf("%d\t", m[k]);
    }
    printf("%d\n");
//    printf("%d\n", m[0][0]);
//    printf("%d\n", m[0][1]);
//    printf("%d\n", m[0][2]);
//    printf("%d\n", m[0][3]);
//    printf("%d\n", m[1][0]);
//    printf("%d\n", m[1][1]);

    printf("sizeof() %d\n", sizeof(m)); //36
    printf("length %d\n", sizeof(m) / sizeof(m[0][0])); //9
}
