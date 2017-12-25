#include "stdio.h"
#include "lagr.c"
#include "gasi.c"

main() {
    double f1(), f2(), z;
    printf("Laguerre:\n");
    z = lagr(0.0, f1, 1);                      /* ���Ƕ�-��˹����������һ������*/
    printf("f1: t1=%2.8f\n", z);
    z = lagr(0.0, f2, -1);                     /* ���Ƕ�-��˹���������ڶ�������*/
    printf("f2: t2=%2.8f\n", z);
    printf("Gauss\n");
    z = gasi(0.0, 1.0e35, 1.0e-9, 10, f1);       /* ����Ӧ��˹����������һ������*/
    printf("f1: t1=%2.8f\n", z);
    z = gasi(-1.0e35, 0.0, 1.0e-9, 10, f2);      /* ����Ӧ��˹���������ڶ�������*/
    printf("f2: t2=%2.8f\n", z);
}

double f1(x)                               /* ��������1*/
double x;
{
double y;
y = x * x * exp(-x);
return(y);
}
double f2(x)                               /* ��������2*/
double x;
{
double y;
y = x * x * exp(x);
return(y);
}
