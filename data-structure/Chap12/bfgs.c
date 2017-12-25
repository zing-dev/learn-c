/*======================================================
// ��������bfgs
// ����������BFGS׼ţ�ٷ�
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
#include "dirmin.c"

int bfgs(x, xmin, n, y0, f, df, eps, itmax)
double *x, *xmin, *y0, eps;

double (*f)();

void (*df)();

int n, itmax;
{
int i, j, it, flag;
double H[41][41], g0[41], dg[41], dx[41], hdg[41];
double y1, tiny, pq1, uij, pq, qhq, qhq1;
if(n>40)                                          /* ���Ǵ���n<��20�����*/
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
for(
i = 0;
i<n;
i++)
{
dx[i] = -g0[i];                               /* ��ʼ����������*/
for(
j = 0;
j<n;
j++)                            /* H�ĳ�ֵ��Ϊn�׵�λ��*/
H[i][j] = 0.0;
H[i][i] = 1.0;
}
it = 0;
flag = 0;
tiny = n * 1.0e-20;
while(it++<itmax)
{
y1 = dirmin(xmin, dx, xmin, n, f, eps, itmax);          /* ��x�����������õ�x. p=dx*/
if(2.0*(*y0 - y1) <=
eps *(fabs(*y0)
+
fabs(y1)
+ tiny))
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
for(
i = 0;
i<n;
i++)
dg[i] = g0[i];                               /* g0�ݴ���dg��*/
(*df)(xmin, g0, n);                              /* �����µ��ϵ�ƫ��*/
for(
i = 0;
i<n;
i++)
dg[i] = g0[i] - dg[i];                       /* q = g1-g0*/
for(
i = 0;
i<n;
i++)
{
hdg[i] = 0.0;
for(
j = 0;
j<n;
j++)
hdg[i] = hdg[i]+H[i][j]*dg[i];           /* H*q */
}
pq = 0.0;
qhq = 0.0;                                       /* ��pT*q ��qT*H*q */
for(
i = 0;
i<n;
i++)
{
pq = pq + dx[i] * dg[i];
qhq = qhq + dg[i] * hdg[i];                    /* qT*H*q */
}
if(pq<tiny || qhq<tiny)                          /* ������*/
{
return(it);
}
pq = 1.0 / pq;
qhq1 = 1.0 / qhq;
for(
i = 0;
i<n;
i++)
dg[i] =
pq *dx[i]
-
qhq1 *hdg[i];               /* u */
for(
i = 0;
i<n;
i++)
for(
j = 0;
j<n;
j++)                                 /* ����H����*/
{
pq1 = pq * dx[i] * dx[j] - qhq1 * hdg[i] * hdg[j];
uij = qhq * dg[i] * dg[j];
H[i][j] = H[i][j] + pq1+
uij;
}
for(
i = 0;
i<n;
i++)                                /* ���´ε���������*/
{
dx[i] = 0.0;
for(
j = 0;
j<n;
j++)
dx[i] = dx[i] - H[i][j]*g0[j];
}
}
printf("exceeding maximum iterations\n");
return(it);
}
