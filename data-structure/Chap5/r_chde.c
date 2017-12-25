#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "r_chol.c"

/*======================================================
// ��������r_chde
// ������������cholesky�ֽⷨ��Գ�����ʵϵ�����󷽳���
// ���������a ��ϵ������b ��������x���صĽ�����
//           n δ֪��������eps ����Ҫ��С��eps��ֵ����Ϊ��0��
// ����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
int r_chde(a, b, x, n, eps)
double *a, *b, *x, eps;
int n;
{
int i, k;
double *u, *y, t;
if((a==NULL)||(b==NULL)||(x==NULL))            /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer is NULL\n");
return(0);
}
u = (double *) malloc(n * n * sizeof(double));        /* ����ռ䲢����Ƿ�ɹ�*/
y = (double *) malloc(n * sizeof(double));
if((u==NULL)||(y==NULL))
{
printf("Memory alloc failed\n");
return(0);
}
i = r_chol(a, n, u, eps);                         /* ���ú�������cholesky�ֽ�*/
if(i==0)                                       /* �ж��Ƿ�ֽ�ɹ�*/
{
printf("Cholesky decomposition failed\n");
return(0);
}
for(
i = 0;
i<n;
i++)                             /* ���y*/
{
t = 0.0;
for(
k = 0;
k<i;
k++)
t = t + u[i * n + k] * y[k];
y[i] = (b[i]-t)/u[
i *n
+i];
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
t = t + u[k * n + i] * x[k];
x[i] = (y[i] - t)/u[
i *n
+i];
}
free(u);                                       /* �ͷſռ�*/
free(y);
return(1);
}
