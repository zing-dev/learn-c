#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "r_mqr.c"                         /* QR�ֽ�ĺ���*/

/*======================================================
// ��������bmqr
// �����������õ������ⲡ̬������
// ���������a ��ϵ������b ��������x���صĽ�����
//           n δ֪��������
//           eps ����Ҫ��iter ������������
// ����ֵ�����͡����гɹ��򷵻ص�������,ʧ���򷵻�0
=========================================================*/
int bmqr(a, b, x, n, eps, iter)
double *a, *b, *x, eps;
int n, iter;
{
int i, k, piter;
double *c, *q, *r, *e, t, fr;
if((a==NULL)||(b==NULL)||(x==NULL))            /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer is NULL\n");
return(0);
}
c = (double *) malloc(n * sizeof(double));
q = (double *) malloc(n * n * sizeof(double));      /* ����ռ䲢����Ƿ�ɹ�*/
r = (double *) malloc(n * sizeof(double));
e = (double *) malloc(n * sizeof(double));
if((c==NULL)||(q==NULL)||(r==NULL)||(e==NULL))
{
printf("Memory alloc failed\n");
return(0);
}
i = r_mqr(a, n, n, q, eps * eps);                    /* ���ú�������QR�ֽ�*/
if(i==0)                                       /* �ж��Ƿ�ֽ�ɹ�*/
{
printf("QR decomposition failed\n");
return(0);
}
for(
i = 0;
i<n;
i++)
{
t = 0.0;
for(
k = 0;
k<n;
k++)
t = t + q[k * n + i] * b[k];
c[i] =
t;                                    /* ���c*/
r[i] = c[i];                                 /* ��ʼ�в�*/
x[i] = 0.0;                                  /* ��ʼ��Ϊ0*/
e[i] = 0.0;                                  /* ��ʼ����Ϊ0*/
}
fr = 1.0;
piter = 0;
while((fr > eps) && (piter<iter))
{
for(
i = n - 1;
i>=0; i--)                        /* ���������e*/
{
t = 0.0;
for(
k = i + 1;
k<n;
k++)
t = t + a[i * n + k] * e[k];
e[i] = (r[i] - t)/a[
i *n
+i];
x[i] = x[i] + e[i];
}
for(
i = 0;
i<n;
i++)                           /* ���²в�*/
{
t = 0.0;
for(
k = i;
k<n;
k++)
t = t + a[i * n + k] * x[k];
r[i] = r[i] -
t;
}
fr = 0.0;                                    /* �����������*/
for(
i = 0;
i<n;
i++)
{
t = fabs(e[i]) / (1 + fabs(x[i]));
if(t > fr)
fr = t;
}
piter++;                                     /* ���µ�������*/
}
free(c);                                       /* �ͷſռ�*/
free(q);
free(r);
free(e);
return(piter);
}
