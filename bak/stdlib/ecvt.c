//
// Created by zhangrongxiang on 2018/2/27 13:23
// File ecvt
//

#include <stdlib.h>
#include <stdio.h>

int main() {
    double d = 12.2223;
    int decpt, sign;
    /*
     * The string itself does not contain a
     *  decimal point; however, the position of the decimal point relative to
     * the start of the string is stored in *decpt.
     *
     * If the sign of number is negative, *sign is set to a
     * nonzero value, otherwise it is set to 0.
     */
    char *rs = ecvt(d, 10, &decpt, &sign);
    if (rs) {
        printf("%s\n", rs);//1222230000
        printf("%d\n", decpt);//2
        printf("%d\n", sign);//0
    }
    rs = ecvt(110.01, 5, &decpt, &sign);
    printf("%s\n", rs);//10010
    printf("%d\n", decpt);//3
    printf("%d\n", sign);//0

    rs = ecvt(-1111.01, 5, &decpt, &sign);
    printf("%s\n", rs);//10010
    printf("%d\n", decpt);//3
    printf("%d\n", sign);//1

    rs = ecvt(0.01, 5, &decpt, &sign);
    printf("%s\n", rs);//10000
    printf("%d\n", decpt);//-1
    printf("%d\n", sign);//0

    rs = ecvt(0.0, 2, &decpt, &sign);
    printf("%s\n", rs);//00
    printf("%d\n", decpt);//0
    printf("%d\n", sign);//0
}