#include "stdio.h"
#include "bsl1.c"                        /* ������������Ҫ��һ�౴����������֧��*/
#include "bsl3.c"
#include "bsl4.c"

main() {
    int n, i;
    double x, y;
    for (i = 1; i <= 8; i++) {
        x = 1.0 * i;
        printf("x=%2.1f\n", x);
        for (n = 1; n <= 4; n++)                        /* ���͵�һ�౴��������*/
        {
            y = bsl3(n, x);
            printf("I(%d)=%e ", n, y);
        }
        printf("\n");
        for (n = 1; n <= 4; n++)                       /* ���͵ڶ��౴��������*/
        {
            y = bsl4(n, x);
            printf("K(%d)=%e ", n, y);
        }
        printf("\n");
    }
    getchar();
}
