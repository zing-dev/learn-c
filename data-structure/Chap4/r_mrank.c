/*======================================================
//��������r_mrank
//������������ʵ�������
//���������mat(����ľ���) m(��������) p(��������) eps(����)
//����ֵ�����гɹ��򷵻ؾ�����ȣ�ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int r_mrank(mat, m, n, eps)

double *mat, eps;
int m, n;
{
int i, j, k, p, is, js, l, v, rank;
double tmp, pivot;
double *cpmat;
if(mat == NULL)                  /* �������ָ���Ƿ�Ϊ��*/
{
printf("matrix pointer is Null.\n");
return(0);
}
cpmat = (double *) malloc(m * n * sizeof(double));  /* �������������ݿ���һ�ݣ������ƻ�*/
for(
i = 0;
i<m *n;
i++)
cpmat[i] = mat[i];
p = m < n ? m : n;                  /* ���m��n�еĽ�С�ߣ����ȵ����ֵ*/
rank = 0;
for(
k = 0;
k<p;
k++)
{
pivot = 0.0;                  /* ѡ��Ԫ*/
for(
i = k;
i<m;
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
is = i;                  /* ��¼����Ԫ��λ��*/
js = j;
}
}
if(pivot<eps)                  /* ��ԪС�ھ���ֵʱ����Ϊ��˹��Ԫ�Ѿ����*/
return(rank);
rank++;                      /* ��Ԫ��Ϊ�㣬�ȼ�1*/
if(is != k)                  /* �ж��Ƿ���Ҫ�����н���*/
for(
j = k;
j<n;
j++)              /* �����н���*/
{
l = k * n + j;
v = is * n + j;
tmp = cpmat[l];
cpmat[l] = cpmat[v];
cpmat[v] =
tmp;
}
if(js != k)
for(
i = k;
i<m;
i++)              /* �����н���*/
{
l = i * n + k;
v = i * n + js;
tmp = cpmat[l];
cpmat[l] = cpmat[v];
cpmat[v] =
tmp;
}
for(
i = k + 1;
i<m;
i++)              /* ��ȥ*/
{
tmp = cpmat[i * n + k] / cpmat[k * n + k];      /* ���ٳ����Ĵ���*/
for(
j = k + 1;
j<n;
j++)          /* ������ȥ*/
cpmat[
i *n
+j] -=
tmp *cpmat[k * n + j];
}
}
free(cpmat);
return(rank);
}
