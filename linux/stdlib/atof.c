//
// Created by zing on 2018/2/13.
//

#include <stdlib.h>
#include <stdio.h>
int main() {
    /* Convert a string to a floating-point number.  */
    //  double atof(const char *str) 把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
    char str[] = "10.1010";
    double d = atof(str);
    printf("%lf\n", d);//10.101000
    char str2[30] = "20.30300 This is test";
    char *ptr;
    double ret;
    ret = strtod(str2, &ptr);
    printf("%lf\n", ret);//20.303000
    printf("%s\n", ptr);// This is test
    /////////////////////////////////////
    printf("%g\n", atof("  -0.0000000123junk")); //-1.23e-08
    printf("%g\n", atof("0.012"));//0.012
    printf("%g\n", atof("15e16"));//1.5e+17
    printf("%g\n", atof("-0x1afp-2"));//-107.75
    printf("%g\n", atof("inF"));//inf
    printf("%g\n", atof("Nan"));//nan
    printf("%g\n", atof("1.0e+309"));   // UB ：超出 double 范围 //inf
    printf("%g\n", atof("0.0"));//0
    printf("%g\n", atof("junk"));       // 无可进行的转换 //0
    printf("%lld\n", atoll("junk"));       // 无可进行的转换 //0
    return 0;
}