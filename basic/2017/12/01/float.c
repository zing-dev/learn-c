//
// Created by zhangrongxiang on 2017/12/4 11:00
// File float
//

#include <stdio.h>
#include <float.h>

int main() {
    printf("The maximum value of float = %.10e\n", FLT_MAX);
    printf("The minimum value of float = %.10e\n", FLT_MIN);

    printf("The number of digits in the number = %.10e\n", FLT_MANT_DIG);
}