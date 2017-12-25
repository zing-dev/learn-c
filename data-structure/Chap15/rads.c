/*=============================================================
// �� �� ����rads
// ������������������
// ��������� x ��Ŵ��������ݵ�����
//            n ���鳤��
//            d ���ݵ�λ��
//            k ÿλ���������[0,k)֮�䣬Ҳ����˵��k���Ƶġ�
// �� �� ֵ����
//==============================================================*/
#include "stdlib.h"

void rads(x, n, d, k)

int *x;
int n, d, k;
{
int i, j, m, k1, *a, *y, flag;

void rads_cout();

a = (int *) malloc(n * sizeof(int));        /* a�Ǵ��һλ���ֵ�����*/
y = (int *) malloc(n * sizeof(int));        /* y�����ڴ���м�����Ŀռ�*/
flag = 0;
k1 = 1;
for(
m = 0;
m<d;
m++)                      /* �ֱ�dλ��������*/
{
if(flag == 0)
{
for(
j = 0;
j<n;
j++)
{
a[j] = x[j]/
k1;             /* �õ��˵�mλ*/
a[j] = a[j]%
k;
}
rads_cout(a, x, y, n, k
);
}
else
{
for(
j = 0;
j<n;
j++)
{
a[j] = y[j]/
k1;             /* �õ��˵�mλ*/
a[j] = a[j]%
k;
}
rads_cout(a, y, x, n, k
);
}
flag = 1 - flag;
k1 = k1 * k;
}
if(flag==1)                                /* ��ʱ��������ݴ����y��*/
for(
j = 0;
j<n;
j++)
x[j] = y[j];
free(a);
free(y);
return;
}

void rads_cout(a, x, y, n, k)                   /* ��x��a���򣬽������y��*/
int *a, *x, *y;
int n, k;
{
int i, j, *c;
c = (int *) malloc((k + 1) * sizeof(int));
for(
i = 0;
i<=
k;
i++)                     /* ���ó�ֵ*/
c[i] = 0;
for(
i = 0;
i<n;
i++)                      /* ͳ�Ƹ���*/
{
j = a[i];
c[j] = c[j]+1;
}
for(
i = 1;
i<=
k;
i++)                     /* ���������ڼ���λ��*/
c[i] = c[i]+c[i-1];
for(
i = n - 1;
i>=0; i--)                   /* ֱ�Ӹ�����λ*/
{
j = a[i];
y[c[j]-1] = x[i];
c[j] = c[j] - 1;
}
free(c);
return;
}
