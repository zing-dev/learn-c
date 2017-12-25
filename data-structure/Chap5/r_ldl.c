#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "smldl.c"                         /* LDL�ֽ�ĺ���*/

/*======================================================
// ��������r_ldl
// ������������LDL�ֽⷨ��ԳƷ�����
// ���������a ��ϵ������b ��������x���صĽ�����
//           n δ֪��������eps ����Ҫ��С��eps��ֵ����Ϊ��0��
// ����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
int r_ldl(a, b, x, n, eps)
double *a, *b, *x, eps;
int n;
{
int i, k;
double *L, *D, *y, *z, t;
if((a==NULL)||(b==NULL)||(x==NULL))            /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer is NULL\n");
return(0);
}
D = (double *) malloc(n * sizeof(double));        /* ����ռ䲢����Ƿ�ɹ�*/
L = (double *) malloc(n * n * sizeof(double));
y = (double *) malloc(n * sizeof(double));
z = (double *) malloc(n * sizeof(double));
if((D==NULL)||(L==NULL)||(y==NULL)||(z==NULL))
{
printf("Memory alloc failed\n");
return(0);
}
i = smldl(a, n, L, D, eps);                        /* ���ú�������LDL�ֽ�*/
if(i==0)                                       /* �ж��Ƿ�ֽ�ɹ�*/
{
printf("LDL decomposition failed\n");
return(0);
}
for(
i = 0;
i<n;
i++)                             /* ���y��z*/
{
t = 0.0;
for(
k = 0;
k<i;
k++)
t = t + L[i * n + k] * y[k];
y[i] = b[i]-
t;
z[i] = y[i]/D[i];
}
for(
i = n - 1;
i>=0; i--)                          /* ���������x*/
{
t = 0.0;
for(
k = i + 1;
k<n;
k++)
t = t + L[k * n + i] * x[k];
x[i] = z[i] -
t;
}
free(D);                                       /* �ͷſռ�*/
free(L);
free(y);
free(z);
return(1);
}
