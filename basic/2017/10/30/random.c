//
// Created by zhangrongxiang on 2017/10/30 14:20
// File random
//

#include<stdio.h>
#include<stdlib.h>

#define random(x) (rand()%x)

void main() {
    for (int x = 0; x < 10; x++)
        printf("%d/n", random(100));
}