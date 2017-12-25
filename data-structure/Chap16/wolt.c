/*=============================================================
// �� �� ����wolt1 (x,n,y)
// �����������ֶ�ʲ�任
// ���������x���任��ʼֵ����n��ϵ����������y���任�����У�
// �� �� ֵ���������֡�����ɹ��򷵻�1�����򷵻�0
//==============================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int wolt(y, n, x)

int n;
double *x, *y;
{
int i, j, k, nn;
double t;

int wolt1(double *x, int n, double *y);    /* ��ΪҪ�ݹ���ã�����������*/
k = log(n - 0.5) / log(2.0) + 1;                  /* ���k��ʹ2^k>=n>2^(k-1) */
nn = 1;                                /* �ж�n�Ƿ���2�������ݣ����ǵĻ��˳�����*/
for(
i = 0;
i<k;
i++)
nn = nn << 1;
if(nn != n)
{
printf("n should be 2^k.\n");
return(0);
}
j = wolt1(y, n, x);                               /* �����Ӻ��������ͷ����еĲ���*/
if(j)
{
t = 1.0 / sqrt(n);
for(
i = 0;
i<n;
i++)                               /* ���Ӻ������صĽ������n^0.5*/
x[i] *=
t;
}
return(j);
}
int wolt1(x, n, y)
int n;
double *x, *y;
{
int i, j, k;
double *x0, *x1, *y0, *y1;
if(n==1)
{                                    /* �����г���Ϊ1ʱ���ֶ�ʲ�任��������*/
y[0] = x[0];
return(1);
}
k = n >> 1;                       /* k��n��һ�룬������С��ģ������Ҫ����ռ��С*/
x0 = (double *) malloc(k * sizeof(double));
x1 = (double *) malloc(k * sizeof(double));
y0 = (double *) malloc(k * sizeof(double));
y1 = (double *) malloc(k * sizeof(double));
if((x0==NULL)||(x1==NULL)||(y0==NULL)||(y1==NULL))
{
printf("memory xlloc failed.\n");
return(0);
}                                                  /* �����зֳ�����*/
for(
i = 0;
i<k;
i++)
{
j = 2 * i;
x0[i] = x[j];
x1[i] = x[j+1];
}                                                  /* �ݹ���ô˺���*/
i = wolt1(x0, k, y0);
j = wolt1(x1, k, y1);
if(
i &&j
)                                /* ���õ��������������ۺ�����*/
{
for(
i = 0;
i<k;
i++)
{                                         /* һ��һ������������е��ۺ�*/
y[i] = y0[i] + y1[i];
y[i+k] = y0[i] - y1[i];
}
}
free(y0);
free(y1);
free(x0);
free(x1);
return(1);
}
