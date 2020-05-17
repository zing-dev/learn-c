//
// Created by zhangrongxiang on 2018/2/26 12:37
// File pow
//

#include <stdio.h>
#include <math.h>

#include <stdio.h>
#include <math.h>

void main() {
    int i, j, m, a, n, sum;
    sum = 0;
    m = 0;
    printf("Please enter the number of a and n:");
    scanf("%d%d", &a, &n);
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            m = m + a * pow(10, j);
        }
        sum = sum + m;
        m = 0;
    }
    printf("The result is %d", sum);
}