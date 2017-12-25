#include "stdio.h"
#include "chii.c"

main() {
    int i, n;
    double x, y;
    for (i = 1; i < 5; i++) {
        x = 1.0 * i;                                     /* xֵ*/
        for (n = 1; n < 4; n++)                           /* nֵ*/
        {
            y = chii(x, n);                               /* �����ֲ�����*/
            printf("P(%2.1f,%d)=%e ", x, n, y);          /* ��ӡ���*/
        }
        printf("\n");
    }
    getchar();
}
