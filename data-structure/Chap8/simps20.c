#include "math.h"
#include "stdio.h"
#include "simps2.c"

main() {
    double a, b, eps, s, h0, f(double, double);
    void fy(double, double []);
    a = 0.0;
    b = 4.0;
    eps = 0.0001;
    h0 = 1e-6;
    s = simps2(a, b, 10, eps, h0, f, fy);        /* ���ú������л���*/
    printf("simps2: s=%2.5f\n", s);         /* ��ӡ���ֽ��*/
    getchar();
}

double f(x, y)                            /* �����ֵĺ���*/
double x, y;
{
double z;
z = exp(-x * y) / (1.0 + x * y);
return(z);
}
void fy(x, y)                             /* ����ֽ�ĺ���*/
double x, y[2];
{
y[0] = 0;
y[1] =
x;
return;
}
