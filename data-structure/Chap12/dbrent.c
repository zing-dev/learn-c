/*======================================================
// ��������dbrent
// ����������ʹ��һ�׵�����Brent�㷨����ֵ
// ���������a ��ʼ�������˵�
//           b ��ʼ������м��
//           c ��ʼ������Ҷ˵�
//           f ����ָ��
//           df ������һ�׵�����ָ��
//           xopt ָ�룬ָ��ֵ�������
//           eps �����޶�
//           itmax ����������
// ����ֵ��  �����ļ�Сֵ
=========================================================*/

#include "stdio.h"
#include "math.h"

double dbrent(a, b, c, f, df, xopt, eps, itmax)

double a, b, c, eps;

double (*f)(double), (*df)(double);

double *xopt;
int itmax;
{
int it, t1, t2;                                      /* �����жϽ���d1����d2*/
double xm, x, u, w, v, fx, fu, fw, fv, du, dv, dw, dx;
double u1, u2, eps1, eps2, d0, d, d1, d2;

x = w = v = b;                                           /*x,w,v�ĳ�ֵΪb*/
fx = fw = fv = (*f)(b);
dx = dw = dv = (*df)(b);
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
d0 = (dx > 0.0) ? a - x : c - x;                      /* ����С����ķ������*/
d = 0.5 * d0;
}
else
{
d2 = d1 = 2.0 * (c - a);
if(dw != dx)                                /* ����w,x����������ŵ���x�ľ���d1*/
d1 = (w - x) / (dx - dw) * dx;
if(dv != dx)                                /* ����v,x����������ŵ���x�ľ���d2*/
d2 = (v - x) / (dx - dv) * dx;
u1 = x + d1;                                  /* ����w,x�õ��Ľ������ŵ�*/
u2 = x + d2;                                  /* ����v,x�õ��Ľ������ŵ�*/
t1 = (a - u1) * (c - u1) < 0.0 && d1 * dx <= 0;         /* u1��a��c֮�䣬���ǵ���С����ķ���*/
t2 = (a - u2) * (c - u2) < 0.0 && d2 * dx <= 0;         /* u1��a��c֮�䣬���ǵ���С����ķ���*/
if(t1||t2)                                  /* ѡ�����u1��u2*/
{
if(
t1 &&t2
)
d = (fabs(d1) < fabs(d2)) ? d1 : d2;      /* �������ɣ���ѡ���С��һ��*/
else if(t1)
d = d1;
else
d = d2;
if(
fabs(d)
>= fabs(0.5*d0))
{
d0 = (dx > 0.0) ? a - x : c - x;              /* ����С����ķ������*/
d = 0.5 * d0;
}
else                                    /* dС���ϴβ�����һ�룬�Ž���*/
{
u = x + d;
if(u-a<eps2 || c-u<eps2)            /* ���ڽӽ����򲻽��ܣ�ֱ�Ӷ�x����΢��*/
d = fabs(eps1) * ((xm - x > 0) ? 1.0 : -1.0);
}
}
else                                        /* u1��u2�����ܽ���ʱ������*/
{
d0 = (dx > 0.0) ? a - x : c - x;                  /* ����С����ķ������*/
d = 0.5 * d0;
}
}
if(
fabs(d)
>=eps1)
u = x + d;
else
{
u = x + fabs(eps1) * ((d > 0) ? 1.0 : -1.0);           /* ��С�Ĳ���*/
fu = (*f)(u);
if(fu > fx)                            /* ���½����������С�Ĳ�����Ȼ���ӣ���˵���Ѿ��ҵ������ŵ�*/
{
*
xopt = x;
return(fx);
}
}
fu = (*f)(u);
du = (*df)(u);
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
dv = dw;
dw = dx;
dx = du;
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
dv = dw;
dw = du;
}
else if(fu<=fv||v==x||v==w)
{
v = u;
fv = fu;
dv = du;
}
}
}
printf("exceed max iterations\n");                   /* ������������*/
*
xopt = x;
return(fx);
}
