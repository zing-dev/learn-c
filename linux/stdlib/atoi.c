//
// Created by zing on 2018/2/13.
//

#include <stdio.h>
#include <stdlib.h>

/* Convert a string to an integer.  */
int main() {
    printf("%d\n", atoi("-123zing"));//-123
    printf("%d\n", atoi("0"));//0
    printf("%i\n", atoi("zing")); //0        // 无可进行的转换
    printf("%i\n", atoi("2147483648"));   // UB ：在 int 范围外-2147483648
    return 0;
}