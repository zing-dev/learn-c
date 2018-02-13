//
// Created by 张荣响 on 2018/2/13.
//

#include <stdlib.h>
#include <stdio.h>
int main() {
//  double atof(const char *str) 把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
    char str[] = "10.1010";
    double d = atof(str);
    printf("%lf\n", d);
    char str2[30] = "20.30300 This is test";
    char *ptr;
    double ret;
    ret = strtod(str2, &ptr);
    printf("%lf\n", ret);
    printf("%s", ptr);
    return 0;
}