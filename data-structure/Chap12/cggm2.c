/*======================================================
// ��������cggm2
// ���������������ݶȷ���ֵ��Polak-Ribire��ʽ
// ���������x[n] ���������ĳ�����
//           xmin[n] �����ҵ������ŵ�
//           y0      ��õļ�Сֵ
//           n ��ʼ�������һ���˵�
//           f ��Ԫ����ָ��
//           df ��Ԫ�����ĵ�������ָ��
//           eps �����޶�
//           itmax ����������
// ����ֵ��  ��������
=========================================================*/
#include "stdlib.h"
#include "math.h"

int cggm2(x, xmin, n, y0, f, df, eps, itmax)

double *x, *xmin, *y0, eps;

double (*f)(), (*df)();

int n, itmax;
{
int i, it, flag;
double g0[21], h[21], g1[21];
double y1, gg0, dgg, v;
if(n>20)                                          /* ���Ǵ���n<��20�����*/
{
printf("you'd better simplify the problem\n");
return(0);
}
for(
i = 0;
i<n;
i++)
xmin[i] = x[i];
*
y0 = (*f)(xmin, n);                              /* ���㺯��ֵ*/
(*df)(xmin, g1, n);                               /* �����ݶ�*/
for(
i = 0;
i<n;
i++)
{
g0[i] = -g1[i];
h[i] = g0[i];
g1[i] = h[i];
}
it = 0;
flag = 0;
while(it<itmax)
{
it++;
y1 = dirmin(xmin, g1, xmin, n, f, eps, itmax);   /* ��x�����������õ�x*/
if(2.0*(*y0 - y1) <=
eps *(fabs(*y0)
+
fabs(y1)
+ 1.0e-25))
{
*
y0 = y1;
flag++;
if(flag == 3)                         /* �������κ���ֵ�ޱ仯���˳�*/
return(it);
}
else
flag = 0;                             /* ���flagΪ0*/
*
y0 = y1;
(*df)(xmin, g1, n);                       /* �����µ��ϵ�ƫ��*/
gg0 = 0.0;
dgg = 0.0;
for(
i = 0;
i<n;
i++)                        /* Polak-Ribire��ʽ*/
{
gg0 = gg0 + g0[i] * g0[i];
dgg = dgg + (g0[i] + g1[i]) * g1[i];
}
if(gg0 == 0.0)
return(it);
v = dgg / gg0;
if(v < 1.0e-25)
return(it);
for(
i = 0;
i<n;
i++)                        /* ����h��g0*/
{
g0[i] = -g1[i];
h[i] = g0[i] +
v *h[i];
g1[i] = h[i];
}
}
printf("exceeding maximum iterations\n");
return(it);
}

