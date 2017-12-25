/*======================================================
//��������r_mdet
//������������ʵ���������ʽֵ
//���������mat(����ľ���) n(�������) eps(����)
//����ֵ�����������ʽֵ
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double r_mdet(mat, n, eps)

double *mat, eps;
int n;
{
int i, j, k, is, js, l, v;
double det, flag, tmp, pivot;
double *cpmat;
if(mat == NULL)                            /* ��������ָ���Ƿ�Ϊ��*/
{
printf("matrix pointer is NULL.\n");
return(0.0);
}
cpmat = (double *) malloc(n * n * sizeof(double));  /* �������������ݿ���һ�ݣ������ƻ�*/
for(
i = 0;
i<n *n;
i++)
cpmat[i] = mat[i];
det = 1.0;                                 /* ��������ʽֵ����*/
flag = 1.0;                                /* �������ԭ����¼����ʽֵ�ķ���*/
for(
k = 0;
k<n-1; k++)           /* ������n-1����ȥ*/
{
pivot = 0.0;                             /* ѡ����Ԫ*/
for(
i = k;
i<n;
i++)
for(
j = k;
j<n;
j++)
{
tmp = fabs(cpmat[i * n + j]);
if(tmp > pivot)
{
pivot = tmp;
is = i;
js = j;
}
}
if(pivot<eps)                          /* ����ҵ�����ԪС��eps������Ϊ��0��*/
{
det = 0.0;                             /*��ʱ����ʽֵҲ��0��*/
return(det);
}
if(is != k)                              /* �ж��Ƿ���Ҫ�н���*/
{
flag = -flag;                          /* �н���һ�Σ�����ʽֵ���*/
for(
j = k;
j<n;
j++)                     /* �����н���*/
{
l = k * n + j;
v = is * n + j;
tmp = cpmat[l];
cpmat[l] = cpmat[v];
cpmat[v] =
tmp;
}
}
if(js != k)                              /* �ж��Ƿ���Ҫ�н���*/
{
flag = -flag;                          /* �н���һ�Σ�����ʽֵ���*/
for(
i = k;
i<n;
i++)                     /* �����н���*/
{
l = i * n + k;
v = i * n + js;
tmp = cpmat[l];
cpmat[l] = cpmat[v];
cpmat[v] =
tmp;
}
}
for(
i = k + 1;
i<n;
i++)                    /* ������ȥ*/
{
tmp = cpmat[i * n + k] / cpmat[k * n + k];          /* ��¼�´�ֵ�����ٳ����Ĵ���*/
for(
j = k + 1;
j<n;
j++)                  /* ��ȥ*/
cpmat[
i *n
+j] -=
tmp *cpmat[k * n + j];
}
det = det * cpmat[k * n + k];           /*����det��ֵ*/
}
det = flag * det * cpmat[k * n + k];        /* ���ո���det��ֵ*/
free(cpmat);
return(det);
}
