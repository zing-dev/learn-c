/*======================================================
//��������r_mqr
//���������������QR�ֽ�
//���������mat ָ����ֽ�ľ����ָ�룬�����Ǵ�ž���R
            m,n �������
            q   ָ�򷵻�Q�����ָ��
            eps ����Ҫ��С�ڴ�ֵ��������Ϊ��0
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int r_mqr(mat, m, n, q, eps)

double *mat, *q, eps;
int m, n;
{
int i, j, k, l, p;
double u, alpha, t;
if((mat==NULL) || (q==NULL))               /* ���ָ���Ƿ�Ϊ��*/
{
printf("The matrix pointer is NULL\n");
return(0);
}
if(m<n)                                    /* Ҫ�����ά����������m>n*/
{
printf("Fail\n");
return(0);
}
for(
i = 0;
i<m;
i++)                         /* Q���󸳳�ֵ�ɵ�λ��*/
{
for(
j = 0;
j<m;
j++)
q[
i *m
+j] = 0.0;
q[
i *m
+i] = 1.0;
}
for(
k = 0;
k<n;
k++)                         /* ѭ����Householder�任*/
{
u = 0.0;
l = k * n + k;
for(
i = k;
i<m;
i++)                       /* ѡȡ����ֵ��itֵ��ʹ�����ȶ�*/
{
t = fabs(mat[i * n + k]);
if(t>u)
u = t;
}
alpha = 0.0;                             /* ����alpha��ֵ*/
for(
i = k;
i<m;
i++)
{
t = mat[i * n + k] / u;
alpha = alpha + t * t;
}
if(alpha<eps)                          /* �ж�alphaֵ�Ƿ����Ϊ0*/
{
printf("Fail\n");                      /* ��alphaֵ��С���������ֹ*/
return(0);
}
t = mat[l];
if(t>0.0)
u = -u;
alpha = u * sqrt(alpha);                   /* ���alphaֵ�ļ���*/
u = sqrt(2.0 * alpha * (alpha - t));           /* ����rouֵ*/
if (u > eps)                             /* �ж�rouֵ�Ƿ����Ϊ0*/
{
mat[l] = (t-alpha)/
u;                  /* �������uk�����ԭ����Ŀռ���*/
for(
i = k + 1;
i<m;
i++)                   /* �������ui�����ԭ����Ŀռ���*/
{
p = i * n + k;
mat[p] = mat[p]/
u;
}
for(
j = 0;
j<m;
j++)                     /* Hk ��� Q*/
{
t = 0.0;
for(
l = k;
l<m;
l++)
t = t + mat[l * n + k] * q[l * m + j];
for(
i = k;
i<m;
i++)
{
p = i * m + j;
q[p] = q[p]-2.0*
t *mat[i * n + k];
}
}
for(
j = k + 1;
j<n;
j++)                   /* Hk ���ԭ���� A*/
{
t = 0.0;
for(
l = k;
l<m;
l++)
t = t + mat[l * n + k] * mat[l * n + j];
for(
i = k;
i<m;
i++)
{
p = i * n + j;
mat[p] = mat[p]-2.0*
t *mat[i * n + k];
}
}
mat[
k *n
+k] =
alpha;
for(
i = k + 1;
i<m;
i++)                   /* ������A�ĵ�k�������ǲ�����Ϊ0*/
mat[
i *n
+k] = 0.0;
}
}
for(
i = 0;
i<m-1; i++)                       /* ת�õõ�����Q*/
for(
j = i + 1;
j<m;
j++)
{
p = i * m + j;
l = j * m + i;
t = q[p];
q[p] = q[l];
q[l] =
t;
}
return(1);
}