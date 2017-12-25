#include "stdio.h"
#include "stdlib.h"
#include "c_comp.c"

/*======================================================
// ��������c_minv
// �����������ø�˹��Լ����ȥ�����и�����ԭ������
// ���������mat ������ľ������ɹ����������
//           n �������
//           eps ����Ҫ��С��eps��ֵ����Ϊ��0��
// ����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
int c_minv(mat, n, eps)
struct c_comp *mat;
int n;
double eps;
{
int *is, *js, i, j, k, l, v;
struct c_comp c_tmp;
double tmp, d;

if(mat == NULL)                     /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The matrix pointer is NULL\n");
return(0);
}

is = malloc(n * sizeof(int));         /* Ϊ�н�����¼����ռ䲢����Ƿ�ɹ�*/
if(is == NULL)
{
printf("Memory alloc failed\n");
return(0);
}

js = malloc(n * sizeof(int));         /* Ϊ�н�����¼����ռ䲢����Ƿ�ɹ�*/
if(js == NULL)
{
free(is);
printf("Memory alloc failed\n");
return(0);
}

for(
k = 0;
k<n;
k++)
{
d = 0.0;
for(
i = k;
i<n;
i++)             /* ��ѭ������ѡȡ��Ԫ*/
for(
j = k;
j<n;
j++)
{
l = i * n + j;
tmp = mat[l].rmz * mat[l].rmz + mat[l].imz * mat[l].imz;  /* ��Ԫ�ص�ģ*/
if(tmp>d)
{
d = tmp;
is[k] =
i;
js[k] =
j;
}
}
if(d<eps)                    /* �ж���Ԫ�Ƿ��С*/
{
free(is);                  /* ����Ԫ��С���˳�����*/
free(js);
printf("Matrix inverse failed.\n");
return(0);
}

if(is[k]!=k)                   /* �ж��Ƿ���Ҫ�н���*/
for (
j = 0;
j<=n-1; j++)       /* �����н���*/
{
l = k * n + j;
v = is[k] * n + j;
tmp = mat[l].rmz;
mat[l].
rmz = mat[v].rmz;
mat[v].
rmz = tmp;
tmp = mat[l].imz;
mat[l].
imz = mat[v].imz;
mat[v].
imz = tmp;
}
if(js[k]!=k)                   /* �ж��Ƿ���Ҫ�н���*/
for (
i = 0;
i<=n-1; i++)       /* �����н���*/
{
l = i * n + k;
v = i * n + js[k];
tmp = mat[l].rmz;
mat[l].
rmz = mat[v].rmz;
mat[v].
rmz = tmp;
tmp = mat[l].imz;
mat[l].
imz = mat[v].imz;
mat[v].
imz = tmp;
}
l = k * n + k;                   /* ��һ������ĵ�һ��*/
mat[l].
rmz = mat[l].rmz / d;
mat[l].
imz = -mat[l].imz / d;

for(
j = 0;
j<=n-1; j++)          /* ��һ������ĵڶ�������Ҫʹ�ø����ĳ˷�*/
if(j!=k)
{
v = k * n + j;
c_comp_product(&mat[v], &mat[l], &mat[v]
);
}

for(
i = 0;
i<=n-1; i++)          /* ��Ԫ����ĵ�һ��*/
if(i!=k)
{
for (
j = 0;
j<=n-1; j++)
if (j!=k)
{
c_comp_product(&mat[k * n + j], &mat[i * n + k], &c_tmp
);
mat[
i *n
+j].
rmz = mat[i * n + j].rmz - c_tmp.rmz;
mat[
i *n
+j].
imz = mat[i * n + j].imz - c_tmp.imz;
}
}

for(
i = 0;
i<=n-1; i++)          /* ��Ԫ����ĵڶ���*/
if(i!=k)
{
v = i * n + k;
c_comp_product(&mat[l], &mat[v], &mat[v]
);
mat[v].
rmz = -mat[v].rmz;
mat[v].
imz = -mat[v].imz;
}
}

for(
k = n - 1;
k>=0; k--)             /* �����н������н�������ʷ���н���ָ�*/
{
if(js[k]!=k)                  /* �ж��Ƿ���Ҫ�ָ�*/
for(
j = 0;
j<=n-1; j++)       /* ���н�������ʷ�����н���*/
{
l = k * n + j;
v = js[k] * n + j;
tmp = mat[l].rmz;
mat[l].
rmz = mat[v].rmz;
mat[v].
rmz = tmp;
tmp = mat[l].imz;
mat[l].
imz = mat[v].imz;
mat[v].
imz = tmp;
}

if(is[k]!=k)
for(
i = 0;
i<=n-1; i++)        /* ���н�������ʷ�����н���*/
{
l = i * n + k;
v = i * n + is[k];
tmp = mat[l].rmz;
mat[l].
rmz = mat[v].rmz;
mat[v].
rmz = tmp;
tmp = mat[l].imz;
mat[l].
imz = mat[v].imz;
mat[v].
imz = tmp;
}
}

free(is);                          /* �ͷŷ���Ŀռ�*/
free(js);
return(1);                         /* ���ɹ�������1*/
}
