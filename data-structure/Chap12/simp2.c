/*======================================================
// ��������simp2
// ���������� ��Լ��������nά��ֵ�ĵ����η�
// ���������n   �����ά��
//           m   ����Լ�������ĸ���
//           a[n] ����Լ��������x���½�
//           b[n] ����Լ��������x���Ͻ�
//           (*sf)() ���㶥���Ƿ����㺯��Լ�������ĺ���
//           d    �����ʼ�����εĲ���
//           alf  ����ϵ����һ��ȡ1.3
//           x[(2n)*n]  ������󵥴��ε�2n����������
//           fx[2n]    �������ĵ����ε�2n�������ϵ�Ŀ�꺯��ֵ
//           xopt[n+1]  ����һ�������εĳ�ʼ��㣬ǰn���������ؼ�Сֵ��n�����꣬���һ���������ؼ�Сֵ
//           f ָ��Ŀ�꺯����ָ��
//         eps ���ƾ���Ҫ��
//         itmax ����������
// ����ֵ��  ��������
=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define TINY 1.0e-7

int simp2(n, m, a, b, d, alf, eps, x, fx, xopt, sf, f, itmax)

int itmax, n, m;
double *a, *b, *x, *fx, *xopt;
double d, alf, eps;

double (*f)();

int (*sf)();

{
int it, in, i, j, h, g, iflag;
double *xt, *xc, ft, fc, fg, fh, flag, tmp, rr, simprn();

if(a==NULL||b==NULL||x==NULL||fx==NULL||xopt==NULL)           /* ���ָ���Ƿ�Ϊ��*/
{
printf("One of pointer is null\n");
return(-1);
}
xt = (double *) malloc(n * sizeof(double));                      /* ����ռ䲢����Ƿ�ɹ�*/
xc = (double *) malloc(n * sizeof(double));
if(xt==NULL||xc==NULL)
{
free(xt);
free(xc);
printf("memory alloc faile\n");
return(-1);
}
j = 0;
while(j<n)                                                /* ����ʼ���Ƿ�����Լ��*/
if(a[j]<=xopt[j] && xopt[j]<=b[j])
j++;
else
{
free(xt);
free(xc);
printf("imput x0 is out of range\n");
return(0);
}
if( !(*sf)(xopt))
{
free(xt);
free(xc);
printf("imput x0 is out of range\n");
return(0);
}
for(
j = 0;
j<n;
j++)
x[j] = xopt[j];                                         /* ��ʼ���*/
fx[0] = (*f)(xopt);
rr = 0.0;
for(
i = 1;
i<2*
n;
i++)                                        /* �����ʼ�ĵ�����*/
for(
j = 0;
j<n;
j++)
x[
i *n
+j] = a[j] +
d *simprn(&rr);
for(
i = 1;
i<2*
n;
i++)                                        /* �����������㺯��Լ������*/
{
it = 1;
in = i * n;
for(
j = 0;
j<n;
j++)                                     /* �����֪��������*/
{
tmp = 0.0;
for(
h = 0;
h<i;
h++)
tmp = tmp + x[h * n + j];
xc[j] = tmp/(1.0*i);
}
iflag = 0;
while(it==1&&iflag<200)
{
it = 0;
for(
j = 0;
j<n;
j++)                              /* ����ʹ�����㳣��Լ������*/
{
if(x[in+j] < a[j])
{
x[in+j] = a[j]+TINY;
it = 1;
}
else if(x[in+j] > b[j])
{
x[in+j] = b[j] - TINY;
it = 1;
}
}
if(it == 0)                                   /* ����ʹ�����㺯��Լ������*/
{
if( !(*sf)(&(x[
i *n
])))
{
for(
j = 0;
j<n;
j++)
x[in+j] = (x[in+j]+xc[j])*0.5;
it = 1;
}
}
iflag++;
}
if(iflag>=200)
{
free(xt);
free(xc);
printf("simplex construction failed\n");
return(0);
}
fx[i] = (*f)(&x[in]);                                  /* ����ڸ��������ϵĺ���ֵ*/
}
flag = 1.0 + eps;                                           /* flag���ڼ��㵥�����н�����*/
it = 0;
while(it++<
itmax &&flag
>eps)
{
ft = fx[0];
fg = fx[0];
h = 0;                                                /* ���*/
g = 0;                                                /* �λ���*/
for(
i = 1;
i<2*
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
}
for(
j = 0;
j<n;
j++)
{
xc[j] = 0.0;                                  /* �����ĵ�n������*/
for(
i = 0;
i<2*
n;
i++)
xc[j] = xc[j]+x[
i *n
+j];
tmp = x[h * n + j];
xc[j] = (xc[j]-tmp)/(2*n-1.0);                /* ȥ��������ƽ��ֵ*/
xt[j] = xc[j]+
alf *(xc[j]
-tmp);               /* �����*/
}
iflag = 1;
while(iflag==1)
{
ft = (*f)(xt);
if(ft > fg)                                    /* ����ʹft<=fg*/
{
for(
j = 0;
j<n;
j++)
xt[j] = (xt[j]+xc[j])*0.5;
ft = (*f)(xt);
}
iflag = 0;
for(
j = 0;
j<n;
j++)                             /* ����ʹ�����㳣��Լ������*/
{
if(xt[j] < a[j])
{
xt[j] = a[j]+TINY;
iflag = 1;
}
else if(xt[j] > b[j])
{
xt[j] = b[j] - TINY;
iflag = 1;
}
}
if(iflag == 0)                                  /* ����ʹ�����㺯��Լ������*/
{
if( !(*sf)(xt))
{
for(
j = 0;
j<n;
j++)
xt[j] = (xt[j]+xc[j])*0.5;
iflag = 1;
}
}
}
for(
j = 0;
j<n;
j++)                                 /* xt=> xh*/
x[
h *n
+j] = xt[j];
fx[h] =
ft;
fc = 0.0;
ft = 0.0;
for(
i = 0;
i<2*
n;
i++)                            /* �󶥵��ƽ������*/
{
tmp = fx[i];
fc = fc + tmp;
ft = ft + tmp * tmp;
}
fc = fc * fc / (2.0 * n);
flag = (ft - fc) / (2.0 * n - 1.0);
}
for(
j = 0;
j<n;
j++)                                 /* �����ж����������Ϊ���Ž�*/
{
xopt[j] = 0.0;
for(
i = 0;
i<2*
n;
i++)
xopt[j] = xopt[j]+x[
i *n
+j];
xopt[j] = xopt[j]/(2.0*n);
}
xopt[n] = (*f)(xopt);
free(xt);
free(xc);
return(it);
}

static double simprn(rr)                               /* ����������ӳ���*/
double *rr;
{
int m;
double s = 65536.0, u = 2053.0, v = 13849.0;
*
rr = v + u * (*rr);
m = *rr / s;
*
rr = *rr - m * s;
return(*rr/s);
}