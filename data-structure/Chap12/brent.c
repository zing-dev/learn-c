/*======================================================
// ��������brent
// ����������Brent�㷨����ֵ
// ���������a ��ʼ�������˵�
//           b ��ʼ������м��
//           c ��ʼ������Ҷ˵�
//           f ����ָ��
//           xopt ָ�룬ָ��ֵ�������
//           eps �����޶�
//           itmax ����������
// ����ֵ��  �����ļ�Сֵ
=========================================================*/

#include "stdio.h"
#include "math.h"

#define G2 0.38196601

double brent(a, b, c, f, xopt, eps, itmax)

double a, b, c, eps;

double (*f)(double);

double *xopt;
int itmax;
{
int it;
double xm, x, u, w, v, fx, fu, fw, fv, eps1, eps2, d0, d;
double p, q, r;                                      /* ���������߲�ֵ*/
x = w = v = b;
fx = fw = fv = (*f)(b);
d0 = 0.0;
for(
it = 0;
it<itmax;
it++)
{
xm = (a + c) * 0.5;
eps1 = eps * fabs(x) + 1.0e-10;
eps2 = 2.0 * eps1;
if((c-a)*0.5 < (eps2-
fabs(x
-xm)))             /* ��������׼��*/
{
*
xopt = x;
return(fx);
}
if(
fabs(d0)
<= eps1)                            /* �ϴα仯̫С���ûƽ�ָ*/
{
d0 = (x > xm) ? a - x : c - x;
d = G2 * d0;
}
else
{
r = (x - w) * (fx - fv);                         /* �����߲�ֵ*/
q = (x - v) * (fx - fw);
p = (x - v) * q - (x - w) * r;
q = 2.0 * (q - r);
if(q>0.0)
p = -p;
q = fabs(q);                                /* �½��Ƶ㲻������������*/
if(
fabs(r)
>fabs(0.5*
q *d0
) || p>=
q *(c
-x) || p<=
q *(a
-x))
{
d0 = (x > xm) ? a - x : c - x;                    /* �ûƽ�ָ*/
d = G2 * d0;
}
else
{
d0 = d;
d = p / q;
u = x + d;
if(u-a<eps2 || c-u<eps2)                 /* �����߲�ֵ�����˵���ڽӽ���������*/
d = fabs(eps1) * ((xm - x > 0) ? 1.0 : -1.0);
}
}
if(
fabs(d)
>=eps1)
u = x + d;
else
u = x + fabs(eps1) * ((d > 0) ? 1.0 : -1.0);
fu = (*f)(u);
if(fu <= fx)                                     /* u��xҪ��*/
{
if(u<x)                                      /* ���ŵ�u��a��c֮��*/
c = x;
else
a = x;
v = w;                                       /* v����һ�ε�w*/
w = x;                                       /* w�Ǵ��ŵ�*/
x = u;                                       /* x�����ŵ�*/
fv = fw;
fw = fx;
fx = fu;
}
else                                             /* x��u��*/
{
if(u>=x)                                     /* ���ŵ�x��a��c֮��*/
c = u;
else
a = u;
if(fu <= fw||w==x)                           /* u�Ǵ��ŵ㣬����w*/
{
v = w;
w = u;
fv = fw;
fw = fu;
}
else if(fu<=fv||v==x||v==w)
{
v = u;
fv = fu;
}
}
}
printf("exceed max iterations\n");                   /* ������������*/
*
xopt = x;
return(fx);
}
