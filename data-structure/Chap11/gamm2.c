/*=============================================================
// �� �� ����gamm2
// ������������ⲻ��ȫ٤������ֵ
// ���������a �Ա���a��ֵ��Ҫ��a>0��
//           x �Ա���x��ֵ��Ҫ��x>=0��
//         e1 ����Ҫ�󣬵����ε��Ƶ�ֵ�仯��С��e1ʱ����Ϊ������
//         e0 ��С����ֵ���ӽ��������ܱ�ʾ����С���ݡ�Ϊ������㣬���������õ�ֵ
// �� �� ֵ������ȫ٤������ֵ
//==============================================================*/
#include "stdio.h"
#include "math.h"
#include "gammln.c"

#define NMAX 100

double gamm2(a, x, e1, e0)
double a, x, e1, e0;
{
int n;
double t, del, gln;
double an, bn, c, d;               /* ��������ʽ������Ҫ�ı���*/
if((x<0.0)||(a<=0))
{
printf("x<0.0 or a<=0.0\n");
return(0.0);
}
if(x<e0)
return(0.0);
gln = gammln(a);
if(x<(a+1.0))                 /* ������ͼ���*/
{
del = 1.0 / a;               /*gamm(a)/gamm(a+1)=1/a*/
t = 1.0 / a;
for(
n = 1;
n<NMAX; n++)
{
del = del * x / (a + n);
t = t + del;
if(
fabs(del)
<
fabs(t)
*e1)          /* ���������Ѿ�����*/
{
t = t * exp(-x + a * log(x) - gln);
return(t);
}
}
printf(" iteration too many times\n");    /* ����NMAX�ε���û������*/
return(0.0);
}
else                          /* ʹ������ʽ����*/
{
bn = x + 1.0 - a;               /* �Ѿ������˵�һ������ʽ*/
c = 1.0 / e0;
d = 1.0 / bn;
t = d;
for(
n = 1;
n<NMAX; n++)
{
an = n * (a - n);              /* �˽ڵ�ϵ��a*/
bn = bn + 2.0;               /* �˽ڵ�ϵ��b*/
d = an * d + bn;
c = bn + an / c;
if(
fabs(d)
< e0)           /* ��С��e0������Ϊ��0*/
d = e0;
if(
fabs(c)
< e0)
c = e0;
d = 1.0 / d;
del = d * c;
t = t * del;
if(
fabs(del
-1.0)<e1)          /* ���������Ѿ�����*/
{
t = exp(-x + a * log(x) - gln) * t;
t = 1.0 - t;
return(t);
}
}
printf(" iteration too many times\n");    /* ����NMAX�ε���û������*/
return(0.0);
}
}
