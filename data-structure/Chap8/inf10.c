#include "stdio.h"
#include "leg1.c"
#include "cheb.c"
#include "gasi.c"

main() {
    double a, b, eps, h0, z;
    double f1(double);
    a = 0.0;
    b = 4.0;
    eps = 1e-8;
    h0 = 1e-5;
    z = leg1(a, b, 4, eps, h0, f1);                     /* �����õ�-��˹���������*/
    printf("lagr: t=%7.6f\n", z);                 /* ��ӡ���*/
    z = cheb(a, b, 4, eps, h0, f1);                     /* ���б�ѩ�����������*/
    printf("cheb: t=%7.6f\n", z);
    z = gasi(a, b, eps, 10, f1);                     /* ������Ӧ��˹���������*/
    printf("gasi: t=%7.6f\n", z);
}

#include "math.h"

double f1(x)
double x;                                      /* �����ֵĺ���*/
{
double y;
y = exp(-x * x) / (1.0 + x * x);
return(y);
}
