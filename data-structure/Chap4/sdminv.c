/*======================================================
//��������sdminv
//�����������Գ���������ԭ������
//���������mat ָ����ֽ�ľ����ָ��
            n �������
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int sdminv(mat, n, eps)

double *mat;
int n;
double eps;
{
int i, j, k;
double p, q, *c;
if(mat == NULL)                    /* ���ָ���Ƿ�Ϊ��*/
{
printf("The matrix pointer is NULL\n");
return(0);
}
c = (double *) malloc(n * sizeof(double)); /* Ϊ��ʱ��������ռ䲢����Ƿ�ɹ�*/
if(c == NULL)
{
printf("Memory alloc failed\n");
return(0);
}
for(
k = 0;
k<n;
k++)               /* ѭ�����*/
{
p = mat[0];
if(p<eps)                   /* �ж��Ƿ���������������*/
{
printf("Fail to invert\n");
free(c);
return(0);
}
p = 1.0 / p;                    /* ��Ҫ���еĶ�γ���ת��Ϊ�˷�*/
for(
i = 1;
i<n-
k;
i++)          /* ������������ǲ���ǰn-k�е�ֵ*/
{
q = mat[i * n];
c[i] = -
q *p;
for(
j = 1;
j<i+1; j++)
mat[(i-1)*n+j-1] = mat[
i *n
+j] +
q *c[j];
}
for(
i = n - k;
i<n;
i++)          /* ������������ǲ����е�n-k������n-1�е�ֵ*/
{
q = mat[i * n];
c[i] =
q *p;
for(
j = 1;
j<i+1; j++)
mat[(i-1)*n+j-1] = mat[
i *n
+j] +
q *c[j];
}
mat[
n *n
-1] =
p;               /* ������������ǲ����е�n�е�ֵ*/
for(
i = 1;
i<n;
i++)
mat[(n-1)*n+i-1] = c[i];
}
for(
i = 0;
i<n-1; i++)             /* ���ݶԳ��ԶԾ���������ǲ��ֽ��и�ֵ*/
for(
j = i + 1;
j<n;
j++)
mat[
i *n
+j] = mat[
j *n
+i];
free(c);                         /* �ͷŷ���Ŀռ�*/
return(1);
}
