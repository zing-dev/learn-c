/*======================================================
//��������r_chol
//�����������Գ�����ʵ�����Cholesky�ֽ�
//���������mat ָ����ֽ�ľ����ָ��
            n �������
            u   ָ�򷵻ص����������ָ��
            eps ����Ҫ��С�ڴ�ֵ��������Ϊ��0
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int r_chol(mat, n, u, eps)

double *mat, *u, eps;
int n;
{
int i, j, k;
double t;
if((mat==NULL)||(u==NULL))                          /* ���ָ���Ƿ�Ϊ��*/
{
printf("One of the pointer is NULL\n");           /* ��Ϊ�����ӡ������Ϣ����������*/
return(0);
}
for(
i = 0;
i<n;
i++)                                  /* ��u���󸳳�ֵΪ�����*/
{
for(
j = 0;
j<n;
j++)
u[
i *n
+j] = 0.0;
}
if(
fabs(mat[0])
< eps)                       /* ��Ҫ�������������ţ���Ҫ����䷶Χ*/
{
printf("Failed.\n");
return(0);
}
u[0] =
sqrt(mat[0]);                                    /* �������*/
for(
i = 1;
i<n;
i++)
{
for(
j = 0;
j<i;
j++)
{
t = 0.0;
for(
k = 0;
k<j;
k++)                            /* ���U[i,j]�е���Ͳ���*/
t = t + u[i * n + k] * u[j * n + k];
u[
i *n
+j] = (mat[
i *n
+j]-t)/u[
j *n
+j];           /* ���U[i,j]*/
}
t = 0.0;
for(
k = 0;
k<i;
k++)
t = t + u[i * n + k] * u[i * n + k];
t = mat[i * n + i] - t;
if(t<eps)                                     /* ����䷶Χ*/
{
printf("Failed.\n");
return(0);
}
u[
i *n
+i] =
sqrt(t);                             /* ���U[i,i]*/
}
return(1);
}
