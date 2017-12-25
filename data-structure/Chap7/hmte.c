#include "stdio.h"
#include "math.h"

/*======================================================
// ��������hmte
// �����������������صȾ��ֵ
// ���������x ��һ����㣬h ���ľ���
//           y ָ����n�����ĺ���ֵ�������ָ��
//           dy ָ����n������һ�׵����������ָ��
//           n ������
//           t ָ���Ĳ�ֵ��
// ����ֵ��  ��ָ����ֵ��ĺ�������ֵ
=========================================================*/
double hmte(x, h, y, dy, n, t)

double x, h, *y, *dy, t;
int n;
{
int i, j, k, p;
double z, tmp, l, ll;
if((y==NULL)||(dy==NULL))      /* �������ָ���Ƿ�Ϊ��*/
{
printf("Pointer is Null\n");
return(0.0);
}
if(n<1)                              /* û���ṩ��㣬����0.0*/
return(0.0);
if(n==1)
{                                    /* ֻ��һ�����ʱ*/
z = y[0] + dy[0] * (t - x);
return(z);
}
if(t < (x+2*h))
{
k = 0;
p = 3;
}
else if(t > (x+(n-3)*h))
{
k = n - 3;
p = 3;
}
else
{
k = (int) ((t - x) / h);                 /* �Ⱦ�ʱ������ֱ�Ӽ������������*/
if(n>7)
{
if(k<4)
{
k = 0;
p = 2;
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
printf("hmte: %d,%d\n",k,k+p-1);      /* ��ӡʹ�õ�����*/
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
l = l * (t - x - j * h) / (i - j);
l = l / pow(h, p - 1);
ll = 0.0;                          /* ����H'(x)*/
for(
j = k;
j<k+
p;
j++)
if(j!=i)
ll = ll + 1.0 / (i - j);
ll = ll / h;
tmp = y[i] + (t - x - i * h) * (dy[i] - 2.0 * y[i] * ll);
z = z + tmp * l * l;;
}
return(z);
}
