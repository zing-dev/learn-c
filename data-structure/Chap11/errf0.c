#include "stdio.h"
#include "errf.c"

main() {
    int i, j;
    double x, t;
    for (i = 0; i < 10; i++)                             /* ����10��*/
    {
        for (j = 0; j < 3; j++)                            /* ÿ��3��*/
        {
            x = 0.1 * (3.0 * i + j);                          /* ����x*/
            t = errf(x);                                /* ������������*/
            printf("erf(%2.1f)=%e ", x, t);               /* ��ӡ���*/
        }
        printf("\n");
    }
    getchar();
}
