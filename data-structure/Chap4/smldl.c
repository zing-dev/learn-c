/*======================================================
//��������smldl
//����������ȫѡ��Ԫ��LDL�ֽ�
//���������mat ָ����ֽ�ľ����ָ��
            n �������
            L   ָ�򷵻ص����������ָ��
            D   ָ�򷵻ش�ŶԽ�Ԫ�ص������ָ��
            eps ����Ҫ��С�ڴ�ֵ��������Ϊ��0
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int smldl(mat, n, L, D, eps)

double *mat, *L, *D, eps;
int n;
{
int i, j, k;
double t;
if((mat==NULL)||(L==NULL)||(D==NULL)) /* ���ָ���Ƿ�Ϊ��*/
{
printf("One of the pointer is NULL\n");            /* ��Ϊ�����ӡ������Ϣ����������*/
return(0);
}
for(
i = 0;
i<n;
i++)                                   /* ��L���󸳳�ֵΪ��λ��*/
{
for(
j = 0;
j<n;
j++)
L[
i *n
+j] = 0.0;
L[
i *n
+i] = 1.0;
}
D[0] = mat[0];
if(
fabs(D[0])
< eps)                               /* ��Ҫ����������Ҫ����䷶Χ*/
{
printf("Failed.\n");
return(0);
}                                                 /* �������*/
for(
i = 1;
i<n;
i++)
{
for(
j = 0;
j<i;
j++)
{
t = 0.0;
for(
k = 0;
k<j;
k++)                            /* ���Lij�е���Ͳ���*/
t = t + L[i * n + k] * L[j * n + k] * D[k];
L[
i *n
+j] = (mat[
i *n
+j]-t)/D[j];               /* ���Lij*/
}
t = 0.0;
for(
k = 0;
k<i;
k++)
t = t + L[i * n + k] * L[i * n + k] * D[k];
D[i] = mat[
i *n
+i]-
t;                            /* ���D[i]*/
if(
fabs(D[i])
< eps)                            /* ����䷶Χ*/
{
printf("Failed.\n");
return(0);
}
}
return(1);
}
