#include "stdio.h"
#include "stdlib.h"
#include "math.h"

/*======================================================
// ��������jaco
// �������������ſ˱ȵ������ⷽ����
// ���������a ��ϵ������b ��������x���صĽ�����
//           n δ֪��������eps ����Ҫ��
//           iter ���������������
// ����ֵ�����͡����гɹ��򷵻ص�������,ʧ���򷵻�0
=========================================================*/
int jaco(a, b, x, n, eps, iter)

double *a, *b, *x, eps;
int n, iter;
{
int i, j, piter = 0;
double fr = 1.0, t, *x2;
if((a==NULL)||(b==NULL)||(x==NULL))            /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer is NULL\n");
return(0);
}
x2 = (double *) malloc(n * sizeof(double));       /* ����ռ䲢����Ƿ�ɹ�*/
if(x2==NULL)
{
printf("Memory alloc failed\n");
return(0);
}
for(
i = 0;
i<n;
i++)
if(
fabs(a[i * n + i])
< 1e-12)               /* ��ΪҪ����������Ҫ����Ƿ��С*/
{
printf("A[%d,%d] is too small,cannot converged",i,i);
return(0);
}
for(
i = 0;
i<n;
i++)                        /* �Խ���������ֵ*/
x[i] = 0.0;
while((fr>eps) && (piter<iter))
{
fr = 0.0;
for(
i = 0;
i<n;
i++)
{
t = 0.0;
for(
j = 0;
j<i;
j++)
t = t + a[i * n + j] * x[j];
for(
j = i + 1;
j<n;
j++)
t = t + a[i * n + j] * x[j];
x2[i] = (b[i] - t)/a[
i *n
+i];            /* ���µ�xֵ*/
t = fabs(x2[i] - x[i]) / (1.0 + fabs(x[i]));  /* �������*/
if(t > fr)
fr = t;
}
for(
i = 0;
i<n;
i++)
x[i] = x2[i];
piter++;                               /* ������������1*/
}
return(piter);
}
