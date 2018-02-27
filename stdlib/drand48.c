//
// Created by zhangrongxiang on 2018/2/27 13:19
// File drand48
//

#include <stdlib.h>
#include <stdio.h>

int main() {
    double r = drand48();
    printf("%lf\n", r);
    return 0;
}