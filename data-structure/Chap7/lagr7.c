#include "stdio.h"
#include "math.h"

/*======================================================
// ��������lagr7
// ������������������ȫ�����ֵ
// ���������x ָ����n���������ݵ������ָ��
//           y ָ����n�����ĺ���ֵ�������ָ��
//           n ������
//           t ָ���Ĳ�ֵ��
// ����ֵ��  ��ָ����ֵ��ĺ�������ֵ
=========================================================*/
double lagr7(x, y, n, t)

double *x, *y, t;
int n;
{
int i, j, k, p;
double z, tmp;
if((x==NULL)||(y==NULL))             /* �������ָ���Ƿ�Ϊ��*/
{
printf("Pointer is Null\n");
return(0.0);
}
if(n<1)                              /* û���ṩ��㣬����0.0*/
return(0.0);
if(n==1)                             /* ֻ��һ����㣬���ش˺���ֵ*/
return(y[0]);
if(n==2)
{
z = (y[0] * (t - x[1]) - y[1] * (t - x[0])) / (x[0] - x[1]);
return(z);
}
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
z = 0.0;
printf("lagr7: %d,%d\n",k,k+p-1);    /* ��ӡʹ�õ�����*/
for(
i = k;
i<k+
p;
i++)                 /* �����ֵ�Ľ��*/
{
tmp = 1.0;
for(
j = k;
j<k+
p;
j++)
if(j!=i)
tmp = tmp * (t - x[j]) / (x[i] - x[j]);
z = z + tmp * y[i];
}
return(z);
}
