//
// Created by zhangrongxiang on 2017/8/16 15:11.
// Copyright (c) 2017 ZRC . All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //puts("Hello World!!!"); /* prints Hello World!!! */
    //二维数组的五种指针表示
    int i;
    int j;
    int a[2][3] = {
        {1, 3, 5},
        {2, 4, 6}
    };
    int *p;
    int (*pRow)[3];

    pRow = a;
    p = &a[0][0];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d", *(pRow[i] + j));
            printf("%d", *(*(pRow + i) + j));
            printf("%d", *(a[i] + j));
            printf("%d", *(*(a + i) + j));
            printf("%d\n", *(p + 3 * i + j));
        }
    }
    for (i = 0; i < 2; i++) {
        printf("%d", *(pRow[i]));
        printf("%d\n", *(*(pRow + i)));
    }
        printf("\n");
    //指针数组
    int m, i1 = 1, j1 = 2, k1 = 3, *pArray[3];
    pArray[0] = &i1;
    pArray[1] = &j1;
    pArray[2] = &k1;
    for (m = 0; m < 3; m++) {
        printf("%d", *pArray[m]);
    }
    return EXIT_SUCCESS;
}