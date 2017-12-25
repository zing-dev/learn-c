/*======================================================
//��������r_matmul
//��������������ʵ���������
//���������a(�����) b(�Ҿ���)  c(�������)
            m(���������) p(���������) n(�Ҿ�������)
//����ֵ�����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"

int r_matmul(a, b, m, p, n, c)

double *a, *b, *c;
int m, p, n;
{
int i, j, k;
double tmp;
if(!(m>0 && p>0 && n>0))                   /* ����������Ľ���*/
{
printf("Dimension of a matrix is incorrect\n");
return(0);
}
if(a == NULL || b == NULL || c == NULL)   /* �������ָ���Ƿ�Ϊ��*/
{
printf("The matrix pointer is NULL\n");
return(0);
}
for(
i = 0;
i<m;
i++)                  /* ѭ����������c�е�ÿ��Ԫ��*/
for(
j = 0;
j<n;
j++)
{
tmp = 0.0;                  /* ��ֵ�ȴ�����ʱ������*/
for(
k = 0;
k<p;
k++)              /* ѭ���ۼ�*/
tmp += a[
i *p
+k]*b[
k *n
+j];
c[
i *n
+j] =
tmp;                   /* ���õ��Ľ���������c��*/
}
return(1);
}
