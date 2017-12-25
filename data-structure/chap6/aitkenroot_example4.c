#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"aitkenroot.c"

void main() {
    double x, eps;
    double *x0 = &x;
    double f(double);
    int max;
    *x0 = 1.0;                              /* ��ֵ�����ȣ�����������*/
    eps = 0.00001;
    max = 60;
    printf("  x(k)         x(k+1)        dis\n");
    if (aitkenroot(x0, f, eps, max))          /* ���ú�����Ⲣ��ӡ���*/
        printf("\n%1.5f\n\n", *x0);
    else
        printf("failed!\n");

}

double f(x)                                 /* ���㺯��ֵ*/
double x;
{
return
x *x
*x-2*x+1;
}