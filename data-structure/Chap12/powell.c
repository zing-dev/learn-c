/*======================================================
// ��������powell
// ����������powell������ֵ
// ���������x[n] ���������ĳ�����
//           ee[n*n] n�������ķ���ÿ��Ϊһ������
//           xmin[n] �����ҵ������ŵ�
//           y0      ��õļ�Сֵ
//           n ��ʼ�������һ���˵�
//           f ��Ԫ����ָ��
//           eps �����޶�
//           itmax ����������
// ����ֵ��  ��������
=========================================================*/
#include "stdlib.h"
#include "math.h"
#include "dirmin.c"

int powell(x, ee, xmin, n, y0, f, eps, itmax)
double *x, *ee, *xmin, *y0, eps;

double (*f)();

int n, itmax;
{
int i, j, it, kk;
double x0[21], x1[21], e[21];
double y1, ymax, del, tmp;
if(n>20)                                          /* ���Ǵ���n<��20�����*/
{
printf("you'd better simplify the problem\n");
return(0);
}
*
y0 = (*f)(x, n);                                  /* ��ʼ�ĺ���ֵ*/
it = 0;                                           /* ��������Ϊ0*/
for(
i = 0;
i<n;
i++)
xmin[i] = x[i];
while(it++ < itmax)
{
for(
i = 0;
i<n;
i++)                            /* ��¼�³�ʼ��x*/
x0[i] = xmin[i];
ymax = *y0;
kk = 0;
del = 0.0;
for(
i = 0;
i<n;
i++)                            /* ��n���������һά����*/
{
for(
j = 0;
j<n;
j++)                        /* ��i����������*/
e[j] = ee[
i *n
+j];
y1 = *y0;
*
y0 = dirmin(xmin, e, xmin, n, f, eps, itmax);  /* ��x�����������õ�x*/
if(y1-*y0 > del)                          /* �½���*/
{
del = y1 - *y0;
kk = i;
}
}
if(2.0*(ymax-(*y0)) <=
eps *(fabs(ymax)
+
fabs(*y0)
)+1.0e-25)
return(it);                              /* ��������Ž�*/
for(
i = 0;
i<n;
i++)                           /* ����*/
{
x1[i] = 2.0*xmin[i] - x0[i];
e[i] = xmin[i] - x0[i];
}
y1 = (*f)(x1, n);                             /* ���ӵ�ĺ���ֵ*/
if(y1<ymax)
{
tmp = 2.0 * (ymax - 2.0 * (*y0) + y1) * (ymax - (*y0) - del) * (ymax - (*y0) - del);
tmp = tmp - del * (ymax - y1) * (ymax - y1);
if(tmp < 0.0)
{
*
y0 = dirmin(xmin, e, xmin, n, f, eps, itmax);
for(
j = 0;
j<n;
j++)
ee[
kk *n
+j] = e[j];               /* ���·�����*/
}
}
}
printf("exceeding maximum iterations\n");
return(it);
}

