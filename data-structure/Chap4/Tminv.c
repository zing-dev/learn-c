/*======================================================
//��������Tminv
//����������Toeplitz�����������
//���������t1 ˫����ʵ��һά�����ָ��
            �����д��n��T�;����һ��Ԫ�ؼ�������Ԫ��
            t2 ˫����ʵ��һά�����ָ��
            ���к�n-1��Ԫ�ش��n��T�;����е�������Ԫ��
            n �������
            mat ���ص��������λ��
            eps ����Ҫ�󣬾���ֵС�ڴ�����ֵ��Ϊ��0
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int Tminv(t1, t2, n, mat, eps)

double *t1, *t2;
int n;
double *mat;
double eps;
{
int i, j, k, l;
double a, tmp, *c, *r, *p;

c = (double *) malloc(n * sizeof(double));    /* Ϊ��ʱ��������ռ�*/
r = (double *) malloc(n * sizeof(double));
p = (double *) malloc(n * sizeof(double));

if (
fabs(t1[0])
< eps)                     /* ��������Ƿ�Ϊ0*/
{
free(c);                                 /* ������Ϊ0�����ͷſռ䲢�˳�*/
free(r);
free(p);
printf("Fail to invert\n");
return(0);
}

a = t1[0];                                /* �����ֵ*/
c[0] = t2[1]/t1[0];
r[0] = t1[1]/t1[0];

for(
k = 0;
k<n-2; k++)                      /* k��0��n-3�����µ�ѭ��*/
{
tmp = 0.0;
for(
j = 1;
j<k+2; j++)                  /* ���һ���ۼӺ�*/
tmp = tmp + c[k + 1 - j] * t2[j];
tmp = (tmp - t2[k + 2]) / a;

for(
i = 0;
i<k+1; i++)              /* �ȴ����p�У���Ϊc[i]��ԭֵ��Ҫʹ��*/
p[i] = c[i] +
tmp *r[k - i];
c[k+1] = -
tmp;                    /* �����c[k+1]��ֵ*/

tmp = 0.0;
for(
j = 1;
j<k+2; j++)              /* �ڶ����ۼӺ�*/
tmp = tmp + r[k + 1 - j] * t1[j];
tmp = (tmp - t1[k + 2]) / a;

for(
i = 0;
i<k+1; i++)
{
r[i] = r[i] +
tmp *c[k - i];     /* ����r[i]��ֵ*/
c[k-i] = p[k-i];              /* c[k-i]��ֵ����ʹ�ã���p�е����ݸ���*/
}
r[k+1] = -
tmp;                    /* �����r[k+i]��ֵ*/

a = 0.0;
for(
j = 1;
j<k+3; j++)              /* ����a��ֵ*/
a = a + t1[j] * c[j - 1];
a = t1[0] - a;
if(
fabs(a)
< eps)                 /* ��a��С�����˳�������������̲��ܼ���*/
{
free(c);                      /* �ͷſռ�*/
free(r);
free(p);
printf("Fail to invert\n");
return(0);
}
}

mat[0] = 1.0/
a;                      /* ������õ�r,c,a���������*/
for(
i = 0;
i<n-1; i++)
{
k = i + 1;
mat[k] = -r[i]/
a;                /* �����ĵ�һ��*/
mat[
k *n
] = -c[i]/
a;              /* �����ĵ�һ��*/
}
for(
i = 0;
i<n-1; i++)                 /* ����������Ԫ��*/
for(
j = 0;
j<n-1; j++)
{
l = (i + 1) * n + j + 1;
k = i * n + j;
mat[l] = mat[k]+(c[i]*r[j] - r[n-2-i]*c[n-2-j])/
a;
}
free(c);                            /* �ͷſռ�*/
free(r);
free(p);
return(1);
}
