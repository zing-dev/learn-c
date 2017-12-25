/*======================================================
// ��������gmqr
// ������������QR�ֽⷨ��ԳƷ�����
// ���������a ��ϵ������b ��������x���صĽ�����
//           m ���̵ĸ�����n δ֪��������
//           eps ����Ҫ��С��eps��ֵ����Ϊ��0��
// ����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int gmqr(a, b, x, m, n, eps)

double *a, *b, *x, eps;
int n;
{
int i, k;
double *c, *q, t;
if((a==NULL)||(b==NULL)||(x==NULL))            /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer is NULL\n");
return(0);
}
if(m<n)
{
printf("m<n, QR decomposition failed\n");
return(0);
}
c = (double *) malloc(m * sizeof(double));
q = (double *) malloc(m * m * sizeof(double));         /* ����ռ䲢����Ƿ�ɹ�*/
if((c==NULL)||(q==NULL))
{
free(c);                                      /* �ͷſռ�*/
free(q);
printf("Memory alloc failed\n");
return(0);
}
i = r_mqr(a, m, n, q, eps);                        /* ���ú�������QR�ֽ�*/
if(i==0)                                       /* �ж��Ƿ�ֽ�ɹ�*/
{
free(c);                                      /* �ͷſռ�*/
free(q);
printf("QR decomposition failed\n");
return(0);
}
for(
i = 0;
i<n;
i++)                             /* ���c*/
{
t = 0.0;
for(
k = 0;
k<m;
k++)
t = t + q[k * m + i] * b[k];
c[i] =
t;
}
for(
i = n - 1;
i>=0; i--)                          /* ���������x*/
{
t = 0.0;
for(
k = i + 1;
k<n;
k++)
t = t + a[i * n + k] * x[k];
x[i] = (c[i] - t)/a[
i *n
+i];
}
free(c);                                      /* �ͷſռ�*/
free(q);
return(1);
}