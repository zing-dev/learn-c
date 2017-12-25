#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include"qrroot.c"

void main() {
    int i, itmax = 60;
    double eps = 0.000001;                             /* ����*/
    static double u[5], v[5];                         /* ��Ÿ��ľ���*/
    static double a[6] = {3.0, 2.0, 4.5, 2.2, 1.0, 2.1};    /* ����ϵ��*/

    i = qrroot(a, 5, u, v, eps, itmax);                        /* ���ú���*/
    if (i > 0)                                         /* �ɹ���ֵ���*/
        for (i = 0; i <= 4; i++)
            printf("%13.7e +j %13.7e\n", u[i], v[i]);
    printf("\n");
}