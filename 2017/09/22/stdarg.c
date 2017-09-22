//
// Created by zhangrongxiang on 2017/9/22 11:16
//

#include <stdarg.h>
#include <stdio.h>

/*
 *计算平均值
 */

float average(int n_values, ...) {
    va_list var_arg;
    int count;
    float sum = 0;

    va_start(var_arg, n_values);    /*准备访问可变参数׼       */

    for (count = 0; count < n_values; count += 1) {
        sum += va_arg(var_arg, int);/*添加取自可变参数列表的值         ֵ*/
    }

    va_end(var_arg);                /*完成处理可变参数       */

    return sum / n_values;
}

void main(int argc, char **argv) {
    printf("the average of 3 and 8 is %f\n", average(2, 3, 8));
    printf("the average of 3 and 8 and 11 is %f\n", average(3, 3, 8, 11));
    return;
}
