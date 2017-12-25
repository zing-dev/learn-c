#include "stdio.h"
#include "beta2.c"

main() {
    int i, j, k;
    double x, a0, b0, y;
    double e1 = 1.0e-7;
    double a[5] = {0.5, 0.5, 5.0};
    double b[5] = {0.5, 5.0, 0.5};
    for (i = 0; i < 3; i++) {
        a0 = a[i];
        b0 = b[i];
        printf("a = %2.1f,b=%2.1f\n", a0, b0);         /* ��ӡa��b*/
        for (j = 0; j < 5; j++)                           /* ��ӡ5��*/
        {
            for (k = 0; k < 2; k++)                         /* ÿ������*/
            {
                x = 0.1 * (2 * j + k);                         /* x��0.0-0.9֮�䣬��10��*/
                y = beta2(a0, b0, x, e1);                     /* ���ú�������*/
                printf("B(x=%2.1f)=%e ", x, y);            /* ��ӡ���*/
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    getchar();
}

