#include "stdio.h"
#include "bsl1.c"
#include "bsl2.c"

main() {
    int n, i;
    double x, y;
    for (i = 1; i <= 8; i++) {
        x = 1.0 * i;
        printf("x=%2.1f\n", x);                  /* ��һ�������ױ���������*/
        for (n = 1; n <= 4; n++) {
            y = bsl1(n, x);
            printf("J(%d)=%1.8f ", n, y);
        }
        printf("\n");
        for (n = 1; n <= 4; n++)                     /* �ڶ��������ױ���������*/
        {
            y = bsl2(n, x);
            printf("Y(%d)=%1.8f ", n, y);
        }
        printf("\n");
    }
    getchar();
}
