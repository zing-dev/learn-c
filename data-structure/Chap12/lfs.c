#include "stdio.h"
#include "math.h"

/*======================================================
// ��������lfs
// ��������������ʽ��ֵ
// ���������x ָ����n���������ݵ������ָ��
//           y ָ����n�����ĺ���ֵ�������ָ��
//           n ������
//           t ָ���Ĳ�ֵ��, eps С�ڴ�����ֵ��Ϊ��0
// ����ֵ��  ��ָ����ֵ��ĺ�������ֵ
=========================================================*/
double lfs(x, y, n, t, eps)

double *x, *y, t, eps;
int n;
{
int i, j, k, p, flag;
double z, u, *b;
if((x==NULL)||(y==NULL))             /* �������ָ���Ƿ�Ϊ��*/
{
printf("Pointer is Null\n");
return(0.0);
}
if(n<1)                              /* û���ṩ��㣬����0.0*/
return(0.0);
if(n==1)                             /* ֻ��һ����㣬���ش˺���ֵ*/
return(y[0]);
k = 0;
if(t<x[2])
{
k = 0;
p = 3;
}
else if(t > x[n-3])
{
k = n - 3;
p = 3;
}
else
{
k = 0;
p = n - 1;                    /* ���ַ�Ѱ�Һ��ʵ�����*/
while((p-k) > 1)
{
j = (k + p) / 2;
if(x[j] < t)
k = j;
else
p = j;
}
if(n>7)
{
if(k<4)
{
k = 0;
p = 2 * p;
}
else if(k>(n-5))
{
p = 2 * (n - 1 - k);
k = n - p;
}
else
{
k = k - 3;
p = 8;
}
}
else
{
k = 0;
p = n;
}
}
b = (double *) malloc((p) * sizeof(double));  /* ����ռ䣬�������ʽ*/
b[0] = y[k];
for(
i = 1;
i<p;
i++)                        /* ��������ʽ*/
{
flag = 0;
u = y[i + k];
for(
j = 0;
j<i;
j++)
{
if(
fabs(u
-b[j])<eps)                    /* Ҫ�������������Ҫ��鷶Χ*/
{
flag = 1;
j = i;                                /* ������Ϊ0,������ʽ����Ϊֹ*/
}
else
u = (x[i + k] - x[j + k]) / (u - b[j]);
}
if(flag == 1)
{                                         /* �������������ֹ����ʽ*/
b[i] = 1.0e35;                          /* ����ʽ�Ľ���*/
p = i;
}
else
b[i] =
u;
}
printf("lfs: %d,%d\n",k,k+p-1);              /* ��ӡ��������ʽ��ʹ�õ�����*/
z = b[p - 1];                                  /* �������ֵ*/
for(
i = p - 2;
i>=0; i--)
z = b[i] + (t - x[i + k]) / z;
free(b);
return(z);
}
