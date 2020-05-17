//
// Created by zhangrongxiang on 2017/10/9 16:32
// File atoi
//

//http://www.man7.org/linux/man-pages/man3/atoi.3.html
#include <stdlib.h>
#include <stdio.h>

int main() {

    char ch[] = "12345.67";
//    int atoi(const char *nptr);
    int i = atoi(ch);
    // 12345
    long l = atol(ch);
    printf("i is %d\n", i);
    printf("l is %d\n", l);
}