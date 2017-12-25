/*======================================================
�ò�ֵ��������Է������ʵ����ʵ��
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "interroot.c"

void main() {
    double x, eps, ab;
    double f(double);
    double *x0 = &x;
    int max;
    *x0 = 1.0;                             /* ��ֵ�����ȣ�����������*/
    ab = 0.0;
    eps = 0.00001;
    max = 60;
    printf("  x(k)         x(k+1)        dis\n");
    if (interroot(x0, ab, f, eps, max))
        printf("\n%1.7f\n", *x0);
    else
        printf("failed!\n");
}

double f(x)                              /* ���㺯��ֵ*/
double x;
{
return
x *x
*x-3*x+1;
}
