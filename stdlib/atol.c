//
// Created by 张荣响 on 2018/2/14.
//

/* atol example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */

int main() {
    long int li;
    char buffer[256];
    printf("Enter a long number: ");
    fgets(buffer, 256, stdin);
    li = atol(buffer);
    printf("The value entered is %ld. Its double is %ld.\n", li, li * 2);

    printf("%ld\n", atol("-123zing"));
    printf("%ld\n", atol("0"));
    printf("%ld\n", atol("zing"));         // 无可进行的转换
    printf("%ld\n", atol("2147483648"));   // UB ：在 int 范围外 2147483648
    return 0;
}