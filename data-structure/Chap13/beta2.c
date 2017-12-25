/*=============================================================
// �� �� ����beta2
// ������������ⲻ��ȫ�������ֵ�ֵ
// ���������a �Ա���a��ֵ��Ҫ��a>0��
//           b �Ա���b��ֵ��Ҫ��b>0��
//           x �Ա���x��ֵ��Ҫ��0<=x<=1��
//         e1 ����Ҫ�󣬵����ε��Ƶ�ֵ�仯��С��e1ʱ����Ϊ������
// �� �� ֵ������ȫ����������ֵ
//==============================================================*/
#include "stdio.h"
#include "math.h"
#include "gammln.c"

#define NMAX 100                         /* ������������*/
#define EULER 0.5772156649
#define FPMIN 1.0e-30                    /* Ϊ��ֹ��0ʹ�õĳ���*/

double beta2(a, b, x, e1)
double a, b, x, e1;
{
double t;

double subcf();                          /* ��������ʽ������Ҫ�ı����ͺ���*/
if((x<0.0)||(x>1.0)||(a<=0.0)||(b<=0.0))
{
printf("Bad input parameter\n");
return(0.0);
}
else if(x == 0.0)                                /* xΪ0�����*/
{
t = 0.0;
return(t);
}
else if(x == 1.0)                                /* xΪ1�����*/
{
t = 1.0;
return(t);
}
else if(x > (a+1.0)/(a+b+2.0))
{
t = exp(gammln(a + b) - gammln(a) - gammln(b) + a * log(x) + b * log(1.0 - x)); /* ϵ��*/
t = 1.0 - t * subcf(b, a, 1.0 - x, e1) / b;               /* ʹ������ʽ����*/
return(t);
}
else
{
t = exp(gammln(a + b) - gammln(a) - gammln(b) + a * log(x) + b * log(1.0 - x)); /* ϵ��*/
t = t * subcf(a, b, x, e1) / a;                       /* ʹ������ʽ����*/
return(t);
}
}

static double subcf(a, b, x, e1)
double a, b, x, e1;
{
int n;
double t, del, an, c, d;
c = 1.0;
d = 1.0 - (a + b) * x / (a + 1.0);
if(
fabs(d)
<FPMIN)
d = FPMIN;
d = 1.0 / d;
t = d;
for(
n = 1;
n<NMAX; n++)
{
an = n * (b - n) * x / ((a + 2.0 * n - 1.0) * (a + 2.0 * n));  /* ��2n�ڵ�ϵ��a,�˽ڵ�ϵ��bΪ1*/
d = an * d + 1.0;                              /* ����d*/
c = 1.0 + an / c;                              /* ����c*/
if(
fabs(d)
< FPMIN)                        /* ���cd�ķ�Χ*/
d = FPMIN;
if(
fabs(c)
< FPMIN)
c = FPMIN;
d = 1.0 / d;
del = d * c;
t = t * del;
an = -(a + n) * (a + b + n) * x / ((a + 2.0 * n) * (a + 1.0 + 2.0 * n));/* ��2n+1��*/
d = 1.0 + an * d;
c = 1.0 + an / c;
if(
fabs(d)
< FPMIN)
d = FPMIN;
if(
fabs(c)
< FPMIN)
c = FPMIN;
d = 1.0 / d;
del = d * c;
t = t * del;
if(
fabs(del
-1.0)<e1)                       /* ���������Ѿ�����*/
return(t);
}
printf("iteration not converged.");          /* û������*/
return(t);
}
