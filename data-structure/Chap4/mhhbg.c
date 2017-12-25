/*======================================================
//��������mhhbg
//�����������������Ʊ任Ϊ���ԽǾ���
//���������mat ָ����ֽ�ľ����ָ�룬����ʱ�����Hessen-Burg����
            n   �������
            q   ָ�򷵻�Q�����ָ��
            eps ����Ҫ��С�ڴ�ֵ��������Ϊ��0
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int mhhbg(mat, n, q, eps)

double *mat, *q, eps;
int n;
{
int i, j, k, l, m, p;
double u, alpha, t, t1, *tmp, *s;
if((mat==NULL)||(q==NULL))                 /* ���ָ���Ƿ�Ϊ��*/
{
printf("The matrix pointer is NULL\n");
return(0);
}
tmp = (double *) malloc(n * sizeof(double));   /* Ϊ��ʱ��������ռ�*/
s = (double *) malloc(n * sizeof(double));     /* Ϊ��ʱ��������ռ�*/

for(
i = 0;
i<n;
i++)                         /* Q���󸳳�ֵ�ɵ�λ��*/
{
for(
j = 0;
j<n;
j++)
q[
i *n
+j] = 0.0;
q[
i *n
+i] = 1.0;
}
for(
k = 0;
k<n-2; k++)                       /* ѭ����Householder�任*/
{
u = 0.0;
l = (k + 1) * n + k;
for(
i = k + 1;
i<n;
i++)                     /* ѡȡ����ֵ��itֵ��ʹ�����ȶ�*/
{
t = fabs(mat[i * n + k]);
if(t>u)
u = t;
}
alpha = 0.0;                             /* ����alpha��ֵ*/
for(
i = k + 1;
i<n;
i++)
{
t = mat[i * n + k] / u;
alpha = alpha + t * t;
}
if(alpha<eps)                          /* �ж�alphaֵ�Ƿ����Ϊ0*/
{
printf("Fail\n");                      /* ��alphaֵ��С���������ֹ*/
free(tmp);
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
i = k + 2;
i<n;
i++)                   /* �������ui�����ԭ����Ŀռ���*/
{
p = i * n + k;
mat[p] = mat[p]/
u;
}
for(
j = 0;
j<n;
j++)                     /* Hk ��� Q*/
{
t = 0.0;
for(
l = k + 1;
l<n;
l++)
t = t + mat[l * n + k] * q[l * n + j];
for(
i = k + 1;
i<n;
i++)
{
p = i * n + j;
q[p] = q[p]-2.0*
t *mat[i * n + k];
}
}
for(
i = k + 1;
i<n;
i++)                    /* Hk ͬʱ��˺��ҳ�ԭ���� A*/
{
t = 0.0;
t1 = 0.0;;
for(
l = k + 1;
l<n;
l++)                  /* �����Ҫ�õ��ĸ���ti��si*/
{
t = t + mat[l * n + k] * mat[l * n + i];
t1 = t1 + mat[i * n + l] * mat[l * n + k];
}
tmp[i] =
t;
s[i] =
t1;
}
for(
i = 0;
i<k+1; i++)
{
t1 = 0.0;
for(
l = k + 1;
l<n;
l++)                  /* si��Ҫ����㼸��*/
t1 = t1 + mat[i * n + l] * mat[l * n + k];
s[i] =
t1;
}
t = 0.0;
for(
m = k + 1;
m<n;
m++)                    /* �������aij��Ҫ����Ͳ���*/
t = t + tmp[m] * mat[m * n + k];
for(
i = k + 1;
i<n;
i++)
for(
j = k + 1;
j<n;
j++)                    /* ����aij*/
{
p = i * n + j;                            /* ���¾���a*/
mat[p] = mat[p]-2.0*tmp[j]*mat[
i *n
+k]-2.0*s[i]*mat[
j *n
+k]
+4.0*mat[
i *n
+k]*
t *mat[j * n + k];
}
for(
i = 0;
i<k+1; i++)
for(
j = k + 1;
j<n;
j++)
{
p = i * n + j;
mat[p] = mat[p]-2.0*s[i]*mat[
j *n
+k];
}
mat[(k+1)*n+k] =
alpha;
for(
i = k + 2;
i<n;
i++)                    /* ������A�ĵ�k�������ǲ�����Ϊ0*/
mat[
i *n
+k] = 0.0;
}
}
for(
i = 0;
i<n-1; i++)                        /* ת�õõ�����Q*/
for(
j = i + 1;
j<n;
j++)
{
p = i * n + j;
l = j * n + i;
t = q[p];
q[p] = q[l];
q[l] =
t;
}
free(tmp);
free(s);                                   /* �ͷſռ�*/
return(1);
}

