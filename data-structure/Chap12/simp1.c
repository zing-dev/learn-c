/*======================================================
// ��������simp1
// ���������� ����Լ��������nά��ֵ�ĵ����η�
// ���������d   �����ʼ�����εı���
//           n   �����ά��
//           lam  ����ϵ����һ��ȡ0-1
//           alf  ����ϵ����һ��ȡ1.0
//           miu  ����ϵ����һ��ȡ1.2-2.0
//           x[(n+1)*n]  ������󵥴��ε�n+1����������
//           fx[n+1]    �������ĵ����ε�n+1�������ϵ�Ŀ�꺯��ֵ
//           xopt[n+1]  ����һ�������εĳ�ʼ��㣬ǰn���������ؼ�Сֵ��n�����꣬���һ���������ؼ�Сֵ
//           f ָ��Ŀ�꺯����ָ��
//         eps ���ƾ���Ҫ��
//         itmax ����������
// ����ֵ��  ��������
=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int simp1(d, n, lam, alf, miu, x, fx, xopt, f, eps, itmax)

double d, lam, alf, miu;
double *x, *fx, *xopt, eps;

double (*f)();

int itmax, n;
{
int it, i, j, h, l, g;
double *xt, *xc, *xe, ft, fc, fe, fg, fh, fl, flag, tmp;

if(x==NULL||fx==NULL||xopt==NULL)                            /* ���ָ���Ƿ�Ϊ��*/
{
printf("One of pointer is null\n");
return(-1);
}
xt = (double *) malloc(n * sizeof(double));                      /* ����ռ䲢����Ƿ�ɹ�*/
xc = (double *) malloc(n * sizeof(double));
xe = (double *) malloc(n * sizeof(double));
if(xt==NULL||xc==NULL||xe==NULL)
{
free(xt);
free(xc);
free(xe);
printf("memory alloc faile\n");
return(-1);
}
for(
i = 0;
i<=
n;
i++)                                          /* �����ʼ�ĵ�����*/
for(
j = 0;
j<n;
j++)
x[
i *n
+j] = xopt[j];
for(
j = 0;
j<n;
j++)
x[(j+1)*n+j] = x[j]+
d;
for(
i = 0;
i<=
n;
i++)                                        /* ����ڸ��������ϵĺ���ֵ*/
fx[j] = (*f)(&x[
i *n
],n);
flag = 1.0 + eps;                                            /* flag���ڼ��㵥�����н�����*/
it = 0;
while(it++<
itmax &&flag
>eps)
{
ft = fx[0];
fe = fx[0];
fg = fx[0];
h = 0;                                                /* ���*/
l = 0;                                                /* ��õ�*/
g = 0;                                                /* �λ���*/
for(
i = 1;
i<=
n;
i++)
{
if(fx[i] > fg)
{
if(fx[i]>fh)                                /* �������ʹλ���*/
{
g = h;
h = i;
}
else                                        /* �����´λ���*/
g = i;
fg = fx[g];
fh = fx[h];
}
else if(fx[i] < fl)                             /* ������õ�*/
{
l = i;
fl = fx[l];
}
}
for(
j = 0;
j<n;
j++)
{
xc[j] = 0.0;                                  /* �����ĵ�n������*/
for(
i = 0;
i<=
n;
i++)
xc[j] = xc[j]+x[
i *n
+j];
tmp = x[h * n + j];
xc[j] = (xc[j]-tmp)/
n;                   /* ȥ��������ƽ��ֵ*/
xt[j] = xc[j]+
alf *(xc[j]
-tmp);           /* �����*/
}
ft = (*f)(xt, n);
if(ft<fx[l])
{
for(
j = 0;
j<n;
j++)                       /* ��չ��xe*/
xe[j] = xt[j]+
miu *(xt[j]
-xc[j]);
fe = (*f)(xe, n);
if(fe<fx[l])                               /* ��xe�滻xh*/
{
for(
j = 0;
j<n;
j++)
x[
h *n
+j] = xe[j];
fx[h] =
fe;
}
else
{
for(
j = 0;
j<n;
j++)                    /* ��xt�滻xh*/
x[
h *n
+j] = xt[j];
fx[h] =
ft;
}
}
else if(ft <= fx[g])
{
for(
j = 0;
j<n;
j++)                    /* ��xt�滻xh*/
x[
h *n
+j] = xt[j];
fx[h] =
ft;
}
else
{
if(ft <= fx[h])
{
for(
j = 0;
j<n;
j++)                    /* ��xt�滻xh*/
x[
h *n
+j] = xt[j];
fx[h] =
ft;
}
for(
j = 0;
j<n;
j++)
xe[j] = xc[j] +
lam *(x[h * n + j]
- xc[j]);
fe = (*f)(xe, n);
if(fe > fx[h])                             /* ��������Ҫѹ��*/
{
for(
i = 0;
i<=
n;
i++)
{
for(
j = 0;
j<n;
j++)
{
x[
i *n
+j] = (x[
i *n
+j]+x[
i *l
+j])*0.5;
}
fx[i] = (*f)(&x[
i *n
],n);
}
}
else
{
for(
j = 0;
j<n;
j++)
x[
h *n
+j] = xe[j];
fx[h] =
fe;
}
}
fc = 0.0;
ft = 0.0;
for(
i = 0;
i<=
n;
i++)                            /* �󶥵��ƽ������*/
{
fc = fc + fx[i];
ft = ft + fx[i] * fx[i];
}
fc = fc * fc / (1.0 + n);
flag = (ft - fc) / n;
}
for(
j = 0;
j<n;
j++)                                 /* �����ж����������Ϊ���Ž�*/
{
xopt[j] = 0.0;
for(
i = 0;
i<=
n;
i++)
xopt[j] = xopt[j]+x[
i *n
+j];
xopt[j] = xopt[j]/(n+1.0);
}
xopt[n] = (*f)(xopt,n);
free(xt);
free(xc);
free(xe);
return(it);
}
