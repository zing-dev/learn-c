#include "stdio.h"
#include "stdlib.h"
#include "math.h"

/*======================================================
// ��������smcg
// �����������ù����ݶȷ���Գ�����������
// ���������a ��ϵ������b ��������x���صĽ�����
//           n δ֪��������
//           eps ����Ҫ��iter ������������
// ����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
int smcg(a, b, x, n, eps, iter)

double *a, *b, *x, eps;
int n, iter;
{
int i, j, k, piter;
double *s, *r, t;
double ta, alpha, tb, tb2, beta;
if((a==NULL)||(b==NULL)||(x==NULL))            /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer is NULL\n");
return(0);
}
s = (double *) malloc(n * sizeof(double));          /* ����ռ䲢����Ƿ�ɹ�*/
r = (double *) malloc(n * sizeof(double));
if((s==NULL)||(r==NULL))
{
printf("Memory alloc failed\n");
return(0);
}
for(
i = 0;
i<n;
i++)
{
r[i] = b[i];                                 /* ��ʼ�в�*/
x[i] = 0.0;                                  /* ��ʼ��Ϊ0*/
s[i] = b[i];                                 /* ��ʼ��������*/
}
tb = 0.0;
for(
k = 0;
k<n;
k++)                             /* ��ʼ��tbֵ*/
tb = tb + r[k] * r[k];
piter = 0;
while((tb > eps) && (piter<iter) && (piter<n))
{
ta = 0.0;
for(
k = 0;
k<n;
k++)                        /* ��ⲽ����ta'ֵ*/
{
t = 0.0;
for(
j = 0;
j<n;
j++)
t = t + a[k * n + j] * s[j];
ta = ta + s[k] * t;
}
alpha = tb / ta;                           /* ����alpha��ֵ*/
for(
k = 0;
k<n;
k++)                        /* ���µĽ�*/
x[k] = x[k]+
alpha *s[k];
for(
k = 0;
k<n;
k++)                           /* ���²в�*/
{
t = 0.0;
for(
j = 0;
j<n;
j++)
t = t + a[k * n + j] * x[j];
r[k] = b[k] -
t;
}
tb2 = 0.0;
for(
k = 0;
k<n;
k++)                           /* ������������*/
tb2 = tb2 + r[k] * r[k];
beta = tb2 / tb;
for(
k = 0;
k<n;
k++)
{
s[k] = r[k] +
beta *s[k];
}
tb = tb2;
piter++;                                     /* ���µ�������*/
}
free(s);
free(r);
return(1);
}
