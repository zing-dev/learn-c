#include "stdio.h"
#include "math.h"

/*======================================================
// ��������hmt
// �����������������ز�ֵ
// ���������x ָ����n���������ݵ������ָ��
//           y ָ����n�����ĺ���ֵ�������ָ��
//           dy ָ����n������һ�׵����������ָ��
//           n ������
//           t ָ���Ĳ�ֵ��
// ����ֵ��  ��ָ����ֵ��ĺ�������ֵ
=========================================================*/
double hmt(x, y, dy, n, t)

double *x, *y, *dy, t;
int n;
{
int i, j, k, p;
double z, tmp, l, ll;
if((x==NULL)||(y==NULL)||(dy==NULL))      /* �������ָ���Ƿ�Ϊ��*/
{
printf("Pointer is Null\n");
return(0.0);
}
if(n<1)                              /* û���ṩ��㣬����0.0*/
return(0.0);
if(n==1)
{                                    /* ֻ��һ�����ʱ*/
z = y[0] + dy[0] * (t - x[0]);
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
printf("hmt: %d,%d\n",k,k+p-1);      /* ��ӡʹ�õ�����*/
for(
i = k;
i<k+
p;
i++)                 /* �����ֵ�Ľ��*/
{
l = 1.0;                           /* ����H(x)*/
for(
j = k;
j<k+
p;
j++)
if(j!=i)
l = l * (t - x[j]) / (x[i] - x[j]);
ll = 0.0;                          /* ����H'(x)*/
for(
j = k;
j<k+
p;
j++)
if(j!=i)
ll = ll + 1.0 / (x[i] - x[j]);
tmp = y[i] + (t - x[i]) * (dy[i] - 2.0 * y[i] * ll);
z = z + tmp * l * l;;
}
return(z);
}
