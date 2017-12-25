/*======================================================
// ��������remez
// �������������һ�±ƽ����������㷨
// ���������a ������˵�
//           b �����Ҷ˵�
//           n �ƽ�����ʽ�Ĵ�����1
//           p ָ�򷵻�n������ʽϵ�������ָ��
//           f ָ�򱻱ƽ��ĺ�����ָ��
//           eps ����Ҫ��һ����1e-7����
//           itmax ����������
// ����ֵ��  ���͡�����ϳɹ��򷵻�1,���򷵻�0
=========================================================*/

#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "r_gaus.c"

void remez(a, b, n, p, f, itmax, eps)
double a, b, *p, (*f)(), eps;
int n, itmax;
{
int i, j, k, n1, m, kk;              /* i,j��ά��������У�kһά����Ԫ�غţ�m��ֵ�����*/
double h, x1, newx, s, t;           /* ��������ƫ������*/
double *x, *ff, *A, *temp, *tempf;
n1 = n + 1;                       /* ������Ľ���*/
x = (double *) malloc(n1 * sizeof(double));
ff = (double *) malloc(n1 * sizeof(double));
A = (double *) malloc(n1 * n1 * sizeof(double));
temp = (double *) malloc(n1 * n1 * sizeof(double));
tempf = (double *) malloc(n1 * sizeof(double));

for (
k = 0;
k<n1;
k++)          /* ��������ȡn+1���б�ѩ�����ʽ�Ľ��������Ϊ��ʼ�㼯*/
{
t = cos((n - k) * 3.1415926 / (1.0 * n));
t = (b + a + (b - a) * t) / 2.0;
x[k] =
t;
}
double pre_mu = 1.0e35;                /* ��֤�����ܹ�����*/
double mu = 1.0;
for (
i = 0;
i<n1;
i++)
{
ff[i] = (*f)(x[i]);
xx[
i *n1
] = 1.0;
for (
j = 1;
j<n;
j++)
xx[
i *n1
+j] = x[i]*xx[
i *n1
+j-1];
xx[
i *n1
+n] =
mu;
mu = -mu;
}                                      /* ��ʼX������*/
/* ���濪ʼ����*/
int flagx;
int times = 0;                         /* ��¼��������*/
while (
times<itmax && fabs(pre_mu - mu)
<eps)
{
for (
i = 0;
i<n1;
i++)              /* ����һ�ݣ���Ϊ���õĺ������ƻ�����*/
{
tempf[i] = ff[i];
for (
j = 0;
j<n1;
j++)
temp[
i *n1
+j] = xx[
i *n1
+j];
}
r_gaus(temp, tempf, p, n,
1e-10);     /* ���ϵ����ƫ��*/
pre_mu = mu;
mu = fabs(p[n]);
x1 = a;
newx = a;                         /* newx��¼���ҵ������ƫ���*/
h = 0.1 * (b - a) / (1.0 * n);
while (x1<b)                    /* ɨ��Ѱ�����ƫ���newx*/
{
s = (*f)(x1);
t = p[n - 1];
for (
i = n - 2;
i>=0; i--)
t = t * x1 + p[i];
if (
fabs(s
-t) > mu)
{
flagx = (s - t) > 0 ? 1 : -1;
mu = fabs(s - t);
newx = x1;
}
x1 = x1 + h;
}
for(
i = 0;
i<n1;
i++)               /* ɨ��Ѱ�����ƫ���Ӧ����λ��m*/
if (newx > x[i])
m = i;
if (newx<x[0])                 /* ������滻��ͬʱ����ϵ������xx�ʹ�ź���ֵ�Ľ������ff*/
{
kk = 0;                      /* ��¼�´��޸ĵ��к�*/
s = (*f)(x[0]);
t = p[n - 1];
for (
i = n - 2;
i>=0; i--)
t = t * x[0] + p[i];
s = s - t;
if (
s *flagx<
0.0)           /* ��ţ���ӵ���ǰ*/
{
for (
k = n - 1;
k>=0; k--)
{
ff[k+1] = ff[k];
x[k+1] = x[k];
}
double *tempxx = xx[n];
for (
i = n;
i>0; i--)
xx[i] = xx[i-1];
xx[0] =
tempxx;
}
}
else if(newx > x[6])
{
kk = 6;                      /* ��¼�´��޸ĵ��к�*/
s = (*f)(x[6]);
t = p[5];
for (
i = 4;
i>=0; i--)
t = t * x[6] + p[i];
s = s - t;
if (
s *flagx<
0.0)           /* ��ţ���ӵ����*/
{
for (
k = 0;
k<6; k++)
{
ff[k] = ff[k+1];
x[k] = x[k+1];
}

double *tempxx = xx[0];
for (
i = 0;
i<6; i++)
xx[i] = xx[i+1];
xx[6] =
tempxx;
}
}
else                              /* ���ֵ��x[m]��x[m+1]֮��*/
{
s = (*f)(x[m]);
t = p[5];
for (
i = 4;
i>=0; i--)
t = t * x[m] + p[i];
s = s - t;
if (
s *flagx
> 0.0)            /* ͬ�ţ����滻x[m]*/
{
kk = m;                   /* ��¼�´��޸ĵ��к�*/
xx[kk][6] = -xx[kk+1][6];
}
else                           /* ��ţ����滻x[m+1]*/
{
kk = m + 1;                  /* ��¼�´��޸ĵ��к�*/
xx[kk][6] = -xx[m][6];
}
}
x[kk] =
newx;
ff[kk] = (*f)(x[kk]);
for (
j = 1;
j<6; j++)
xx[kk][j] = x[kk]*xx[kk][j-1];
times++;
}
free(x);
free(ff);
free(A);
free(Xemp);
free(tempf);
}
