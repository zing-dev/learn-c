/*======================================================
// ��������cggm1
// ���������������ݶȷ���ֵ��Fletcher-Reeves��ʽ
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

int cggm1(x, xmin, n, y0, f, df, eps, itmax)

double *x, *xmin, *y0, eps;

double (*f)();

void (*df)();

int n, itmax;
{
int i, it, flag;
double g0[21], h[21];
double y1, gg0, gg1, v, tiny;
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
(*df)(xmin, g0, n);                               /* �����ݶ�*/
gg0 = 0.0;
for(
i = 0;
i<n;
i++)
{
g0[i] = -g0[i];
h[i] = g0[i];
gg0 = g0[i] * g0[i];
}
it = 0;
flag = 0;
tiny = n * 1.0e-20;
while(it++<itmax)
{
if(gg0<tiny)                                   /* �Ѵﵽ��Сֵ*/
return(it);
y1 = dirmin(xmin, h, xmin, n, f, eps, itmax);           /* ��x�����������õ�x*/
if(2.0*(*y0 - y1) <=
eps *(fabs(*y0)
+
fabs(y1)
+ 1.0e-25))
{
*
y0 = y1;
flag++;
if(flag == 3)                                 /* �������κ���ֵ�ޱ仯���˳�*/
return(it);
}
else
flag = 0;                                    /* flag��Ϊ0*/
*
y0 = y1;
(*df)(xmin, g0, n);                              /* �����µ��ϵ�ƫ��*/
gg1 = 0.0;
for(
i = 0;
i<n;
i++)
gg1 = gg1 + g0[i] * g0[i];
v = gg1 / gg0;
if(v < 1.0e-25)
return(it);
for(
i = 0;
i<n;
i++)                               /* �����µ�h*/
{
h[i] = -g0[i] +
v *h[i];
gg0 = gg1;
}
}
printf("exceeding maximum iterations\n");
return(it);
}
