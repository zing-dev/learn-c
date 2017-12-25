/*======================================================
//��������r_chdet
//������������Գ��������������ʽֵ
//���������mat(����ľ���) n(�������) eps(����)
//����ֵ�����������ʽֵ
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double r_chdet(mat, n, eps)

int n;
double *mat, eps;
{
int i, j, k, l, v;
double det;
double *cpmat;
if(mat == NULL)                                /* ��������ָ���Ƿ�Ϊ��*/
{
printf("matrix pointer is NULL.\n");
return(0.0);
}
cpmat = (double *) malloc(n * n * sizeof(double));   /* �������������ݿ���һ�ݣ������ƻ�*/
for(
i = 0;
i<n *n;
i++)
cpmat[i] = mat[i];
det = 1.0;                                       /* ����ֵ*/
for(
k = 0;
k<n;
k++)
{
l = k * n + k;
for(
j = 0;
j<k;
j++)                           /* ���Lkk*/
{
v = k * n + j;
cpmat[l] = cpmat[l]-cpmat[v]*cpmat[v];
}
if(cpmat[l] < eps)                           /* �жϾ����Ƿ�Ϊ����*/
{
printf("matrix is Not positive definite.\n");
return(0.0);
}
cpmat[l] =
sqrt(cpmat[l]);
det = det * cpmat[l];                              /* ����det*/
for(
i = k + 1;
i<n;
i++)                            /* ���Lik*/
{
v = i * n + k;
for(
j = 0;
j<k;
j++)
cpmat[v] = cpmat[v] - cpmat[
i *n
+j]*cpmat[
k *n
+j];
cpmat[v] = cpmat[v]/cpmat[l];
}
}
det = det * det;                                     /* ����ʽֵ��det��ƽ��*/
free(cpmat);
return(det);
}
