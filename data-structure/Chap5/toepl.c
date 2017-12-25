/*======================================================
//��������toepl
//��������������в����ȷ�����
//���������t ָ����n���в����Ⱦ���Ԫ�ص������ָ��
//          b ָ���ų������������ָ��
//          x ָ�򷵻صĽ����������ָ��
//          n �������
//          eps ����Ҫ��С�ڴ�ֵ��������Ϊ��0
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int toepl(t, b, x, n, eps)

double *t, *b, *x, eps;
int n;
{
int i, j, k;
double beta, s1, s, p, q, *y, *yy;
if((t==NULL)||(b==NULL)||(x==NULL))                /* ���ָ���Ƿ�Ϊ��*/
{
printf("One of the pointer is NULL\n");          /* ��Ϊ�����ӡ������Ϣ����������*/
return(0);
}
y = (double *) malloc(n * sizeof(double));
yy = (double *) malloc(n * sizeof(double));
if((y==NULL)||(yy==NULL))                          /* ����ռ䲢����Ƿ�ɹ�*/
{
printf("Memory alloc failed\n");
free(y);
free(yy);
return(0);
}
for(
i = 0;
i<n;
i++)                                 /* ��y��yy���鸳��ֵΪ��*/
{
y[i] = 0.0;
yy[i] = 0.0;
}
if(
fabs(t[0])
< eps)                               /* ��Ҫ����������Ҫ����䷶Χ*/
{
free(y);
free(yy);
printf("Failed.\n");
return(0);
}
y[0] = 1.0/t[0];                                   /* �趨��ֵ*/
x[0] = b[0]/t[0];
for(
k = 1;
k<n;
k++)                                 /* �������*/
{
beta = 0.0;
for(
i = 0;
i<k;
i++)                               /* ���beta*/
beta = beta + t[i + 1] * y[i];
s1 = 1.0 - beta * beta;
if(
fabs(s1)
< eps)                              /* ��Ҫ����������Ҫ����䷶Χ*/
{
free(y);
free(yy);
printf("Failed.\n");
return(0);
}
p = 1.0 / s1;                                     /* ����p��s*/
s = -beta / s1;
yy[0] =
s *y[k - 1];
for(
i = 1;
i<k;
i++)                              /* ���Ƽ���yy*/
yy[i] =
p *y[i - 1]
+
s *y[k - 1 - i];
yy[k] =
p *y[k - 1];
q = 0.0;
for(
i = 0;
i<k;
i++)
q = q + t[k - i] * x[i];
s = b[k] - q;                                     /* ���Ƽ���x*/
for(
i = 0;
i<k;
i++)
x[i] = x[i] +
s *yy[i];
x[k] =
s *yy[k];
for(
i = 0;
i<k+1; i++)                            /* ��yy��ֵ����y*/
y[i] = yy[i];
}
free(y);
free(yy);
return(1);
}
