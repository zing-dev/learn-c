#include "stdio.h"
#include "stdlib.h"
#include "math.h"

/*======================================================
// ��������b_gsjd
// �����������ø�˹��ȥ�������Է�����
// ���������a ��ϵ������b ��������x���صĽ�����
//           n δ֪��������eps ����Ҫ��С��eps��ֵ����Ϊ��0��
// ����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
int b_gsjd(a, b, x, n, eps)

double *a, *b, *x, eps;
int n;
{
int i, j, k, l, v, is, *js;
double tmp, d;
if((a==NULL)||(b==NULL)||(x==NULL))             /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer is NULL\n");
return(0);
}
js = malloc(n * sizeof(int));          /* Ϊ�н�����¼����ռ䲢����Ƿ�ɹ�*/
if(js == NULL)
{
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
i++)                              /* ��ѭ������ѡȡ��Ԫ*/
for(
j = k;
j<n;
j++)
{
l = i * n + j;
tmp = fabs(a[l]);                             /* ��Ԫ�ص�ģ*/
if(tmp>d)
{
d = tmp;
is = i;
js[k] =
j;
}
}
if(d<eps)                                     /* �ж���Ԫ�Ƿ��С*/
{
free(js);
printf("failed.\n");
return(0);                                    /* ����Ԫ��С���˳�����*/
}
if(is!=k)                                       /* �ж��Ƿ���Ҫ�н���*/
{
for (
j = 0;
j<n;
j++)                           /* �����н���*/
{
l = k * n + j;
v = is * n + j;
tmp = a[l];
a[l] = a[v];
a[v] =
tmp;
}
tmp = b[k];                              /* ��������ҲҪ�����н���*/
b[k] = b[is];
b[is] =
tmp;
}
if(js[k]!=k)                                   /* �ж��Ƿ���Ҫ�н���*/
for(
i = 0;
i<n;
i++)                           /* �����н���*/
{
l = i * n + k;
v = i * n + js[k];
tmp = a[l];
a[l] = a[v];
a[v] =
tmp;
}
l = k * n + k;                                /* ȡ����������ת��Ϊ�˷�*/
a[l] = 1.0/a[l];
for(
j = k + 1;
j<n;
j++)
{
v = k * n + j;
if(a[v]!=0.0)
a[v] = a[v]*a[l];
}
b[k] = a[l]*b[k];                           /* ���������Ĺ�һ������*/
for(
i = 0;
i<n;
i++)                          /* ��Ԫ����*/
{
if(i!=
k &&(a[i * n + k]
!=0.0))
{
for(
j = k + 1;
j<n;
j++)
{
if(a[
k *n
+j] != 0.0)
a[
i *n
+j] -= a[
i *n
+k]*a[
k *n
+j];
}
b[i] -= a[
i *n
+k]*b[k];                  /* ��������ҲҪ������Ԫ����*/
}
}
}
for(
i = 0;
i<n;
i++)                            /* ���ڵ�b���ǽ�����*/
x[i] = b[i];
for(
k = n - 1;
k>=0; k--)                        /* �����н�������ʷ���н���ָ�*/
{
if(js[k]!=k)                               /* �ж��Ƿ���Ҫ�ָ�*/
{
tmp = x[k];                              /* �ָ����˳��*/
x[k] = x[js[k]];
x[js[k]] =
tmp;
}
}
free(js);                                    /* �ͷŷ���Ŀռ�*/
return(1);                                   /* ���ɹ�������1*/
}
