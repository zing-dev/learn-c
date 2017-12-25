#include "stdio.h"
#include "r_chde.c"
#include "r_ldl.c"

main() {
    int i, j;
    double a[5][5] = {{24.0, 7.0,  5.0,  2.0,  -1.0},
                      {7.0,  21.0, 6.0,  3.0,  -2.0},
                      {5.0,  6.0,  17.0, -7.0, 1.0},
                      {2.0,  3.0,  -7.0, 11.0, 8.0},
                      {-1.0, -2.0, 1.0,  8.0,  15.0}};   /* ����A */
    double b[5] = {4.0, 6.5, 1.5, -2.5, 12.0}, x[5];            /* ����������ֵ*/
    /*�������㷨���ƻ����ݣ���˲���Ҫ����*/
    r_ldl(a, b, x, 5, 1e-16);                                /* ����LDL�ֽⷨ���*/
    printf("LDL DECO:\n");                               /* ��ӡLDL�ֽⷨ�Ľ��*/
    for (i = 0; i < 5; i++)
        printf("%2.5f\n", x[i]);
    printf("\n");
    r_chde(a, b, x, 5, 1e-16);                               /* ����Cholesky�ֽⷨ���*/
    printf("CHOLESKY:\n");                               /* ��ӡCholesky�ֽⷨ�Ľ��*/
    for (i = 0; i < 5; i++)
        printf("%2.5f\n", x[i]);
}
