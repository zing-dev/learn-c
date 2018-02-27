//
// Created by zhangrongxiang on 2018/2/27 13:12
// File div
//

#include <stdlib.h>
#include <stdio.h>

/*
typedef struct _div_t {
    int quot;
    int rem;
} div_t;
*/

int main() {
    int a = 10;
    int b = 5;
    div_t c = div(a, b);
    printf("%d\n", c.quot);//2 商
    printf("%d\n", c.rem);//0 余数
    c = div(23, 12);
    printf("%d\n", c.quot);//1 商
    printf("%d\n", c.rem);//11 余数

    ldiv_t ld = ldiv(2222, 13);
    printf("%ld\n", ld.quot);//170
    printf("%ld\n", ld.rem);//12
    return 0;
}