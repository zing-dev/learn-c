#include "stdio.h"
#include "b_gsjd.c"
#include "r_trzg.c"
#include "r_gsband.c"

main() {
    int i, j;
    double a[4][4] =
            {{0.2368, 0.2471, 0.0,    0.0},
             {0.1968, 0.2071, 1.2168, 0.0},
             {0.0,    1.1675, 0.1768, 0.1871},
             {0.0,    0.0,    0.1397, 0.1490}};         /* ϵ������*/
    double b[4] = {1.8471, 1.7471, 1.6471, 1.5471};  /* ��������*/
    double a1[4][4], a2[4][4], b1[4], b2[4], x[4], x1[4], x2[4];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            a1[i][j] = a[i][j];            /* ���ú������ƻ����ݣ������Ҫ����һ��*/
            a2[i][j] = a[i][j];
        }
        b1[i] = b[i];                    /* ���ú������ƻ����ݣ������Ҫ����һ��*/
        b2[i] = b[i];
    }
    printf("Big Sparse Gauss:\n");      /* ����ϡ�����*/
    if (b_gsjd(a1, b1, x1, 4, 1e-16) != 0)
        for (i = 0; i < 4; i++)
            printf("x(%d)=%2.5f\n", i, x1[i]);
    printf("\nTR ZG:\n");                 /* ׷�Ϸ�*/
    if (r_trzg(a2, b2, x2, 4, 1e-16) != 0)
        for (i = 0; i < 4; i++)
            printf("x(%d)=%2.5f\n", i, x2[i]);
    printf("\nGauss band:\n");            /* ���;���ⷨ*/
    if (r_gsband(a, b, x, 4, 1, 1e-16) != 0)
        for (i = 0; i < 4; i++)
            printf("x(%d)=%2.5f\n", i, x[i]);
}
