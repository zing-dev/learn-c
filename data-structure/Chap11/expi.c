/*=============================================================
// �� �� ����expi
// �������������ָ�����ֵ�ֵ
// ���������n �Ա���n��ֵ��Ҫ��a>0��
//           x �Ա���x��ֵ��Ҫ��x>=0��
//         e1 ����Ҫ�󣬵����ε��Ƶ�ֵ�仯��С��e1ʱ����Ϊ������
// �� �� ֵ������ȫ٤������ֵ
//==============================================================*/
#include "stdio.h"
#include "math.h"

#define NMAX 100
#define EULER 0.5772156649
#define FPMIN 1.0e-30

double expi(n, x, e1)

int n;
double x, e1;
{
int i, j;
double t, t2, del;
double a, b, c, d;                                  /* ��������ʽ������Ҫ�ı���*/
if((x<0.0)||(n<0)||(x==0.0 &&(n<2)))
{
printf("%2.1f,%d",x,n);
printf("bad input parameter\n");
return(0.0);
}
else if(x == 0.0)                                /* xΪ0�����*/
{
t = 1.0 / (n - 1.0);
return(t);
}
else if(n == 0)                                  /* nΪ0�����*/
{
t = exp(-x) / x;
return(t);
}
else if(x > 1.0)                                 /* ʹ������ʽ����*/
{
b = x + n;                                       /* �Ѿ������˵�һ������ʽ*/
c = 1.0 / FPMIN;
d = 1.0 / b;
t = d;
for(
i = 1;
i<NMAX; i++)
{
a = -i * (n - 1 + i);                               /* �˽ڵ�ϵ��a*/
b = b + 2.0;                                    /* �˽ڵ�ϵ��b*/
d = a * d + b;
c = b + a / c;                                    /* c���Ǵ���0*/
d = 1.0 / d;                                    /* d���Ǵ���0*/
del = d * c;
t = t * del;
if(
fabs(del
-1.0)<e1)                          /* ���������Ѿ�����*/
{
t = exp(-x) * t;
return(t);
}
}
}
else                                              /* ʹ����ͼ���*/
{
t = (n == 1) ? (-log(x) - EULER) : (1.0 / (n - 1));
t2 = 1.0;
for(
i = 1;
i<NMAX; i++)
{
t2 = -t2 * x / i;
if(i != (n-1))
del = -t2 / (i - n + 1);
else
{
del = -EULER;                               /* phi(n)�ļ���*/
for(
j = 1;
j<n;
j++)
del = del + 1.0 / j;
del = t2 * (-log(x) + del);
}
t = t + del;
if(
fabs(del)
<
fabs(t)
*e1)                      /* ���������Ѿ�����*/
return(t);
}
}
printf(" iteration too many times\n");            /* ����NMAX�ε���û������*/
return(0.0);
}
