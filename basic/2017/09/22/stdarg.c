//
// Created by zhangrongxiang on 2017/9/22 11:16
//

#include <stdarg.h>
#include <stdio.h>

/*
 *计算平均值
 */

float average(int n_values, ...) {
//  va_list类型用于声明一个变量，该变量将依次引用各参数。
    va_list var_arg;
    int count;
    float sum = 0;

//  Ava_start宏将va_list声明的变量初始化为指向第一个无名参数的指针。
//  在使用变量之前，该宏必须被调用一次。参数表必须至少包括一个有名参数，va_start将最后一个有名参数作为起点。
    va_start(var_arg, n_values);    /*准备访问可变参数׼       */

    for (count = 0; count < n_values; count += 1) {
//  va_start宏将va_list声明的变量初始化为指向第一个无名参数的指针。
//  在使用变量之前，该宏必须被调用一次。参数表必须至少包括一个有名参数，va_start将最后一个有名参数作为起点。
        sum += va_arg(var_arg, int);/*添加取自可变参数列表的值         ֵ*/
    }
//    va_end宏，该宏必须在函数返回之前调用，以完成一些必要的清理工作。
    va_end(var_arg);                /*完成处理可变参数       */

    return sum / n_values;
}

void main(int argc, char **argv) {
    printf("the average of 3 and 8 is %f\n", average(2, 3, 8));
    printf("the average of 3 and 8 and 11 is %f\n", average(3, 3, 8, 11));
    return;
}
