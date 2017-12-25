/*======================================================
//��������r_mlu
//����������ȫѡ��Ԫ��LU�ֽ�
//���������mat ָ����ֽ�ľ����ָ��
            n �������
            L,U ָ�򷵻ص�������������������ָ��
            P,Q ָ�򷵻صĳ������б任���ָ��
            eps ����Ҫ��С�ڴ�ֵ��������Ϊ��0
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int r_mlu(mat, n, L, U, P, Q, eps)

double *mat, *L, *U, *P, *Q, eps;
int n;
{
int i, j, k, is, js, l, v, kk, ii;
double tmp, pivot;

if((mat==NULL)||(L==NULL)||(U==NULL)||(P==NULL)||(Q==NULL)) /* ���ָ���Ƿ�Ϊ��*/
{
printf("One of the pointer is NULL\n");            /* ��Ϊ�����ӡ������Ϣ����������*/
return(0);
}
for(
i = 0;
i<n;
i++)                                   /* ΪP��Q���󸳳�ֵΪ��λ��*/
{
for(
j = 0;
j<n;
j++)
{
P[
i *n
+j] = 0.0;
Q[
i *n
+j] = 0.0;
}
P[
i *n
+i] = 1.0;
Q[
i *n
+i] = 1.0;
}
for(
k = 0;
k<n-1; k++)
{
pivot = 0.0;                                         /* ѡȡ��Ԫ*/
for(
i = k;
i<n;
i++)
for(
j = k;
j<n;
j++)
{
tmp = fabs(mat[i * n + j]);
if(tmp > pivot)
{
pivot = tmp;
is = i;
js = j;
}
}

if(pivot<eps)                                     /* �ж���Ԫ�Ƿ�Ϊ0*/
{
printf("Fail\n");                                 /* ����ԪΪ0,��������*/
return(0);
}
if(is != k)                                         /* �ж��Ƿ���Ҫ�н���*/
{
for(
j = 0;
j<n;
j++)
{
l = k * n + j;                                     /* �Դ��ֽ��������н���*/
v = is * n + j;
tmp = mat[l];
mat[l] = mat[v];
mat[v] =
tmp;

tmp = Q[l];                                      /* ��P��������н���*/
Q[l] = Q[v];
Q[v] =
tmp;
}
}
if(js != k)                                         /* �ж��Ƿ���Ҫ�н���*/
{
for(
i = 0;
i<n;
i++)
{
l = i * n + k;                                   /* �Դ��ֽ��������н���*/
v = i * n + js;
tmp = mat[l];
mat[l] = mat[v];
mat[v] =
tmp;

tmp = P[l];                                     /* ��Q��������н���*/
P[l] = P[v];
P[v] =
tmp;
}
}
kk = k * n + k;
tmp = 1.0 / mat[kk];                                 /* ���¾���a�е�Ԫ��*/
for(
i = k + 1;
i<n;
i++)
{
l = i * n + k;
mat[l] = mat[l]*
tmp;
for(
j = k + 1;
j<n;
j++)
{
v = i * n + j;
mat[v] = mat[v]-mat[l]*mat[
k *n
+j];
}
}
}

for(
i = 0;
i<n;
i++)
for(
j = 0;
j<n;
j++)                                  /* ����L�����U����*/
{
l = i * n + j;
if(j<i)
{
L[l] = mat[l];
U[l] = 0.0;
}
else if(j == i)
{
L[l] = 1.0;
U[l] = mat[l];
}
else
{
L[l] = 0.0;
U[l] = mat[l];
}
}
return(1);
}
