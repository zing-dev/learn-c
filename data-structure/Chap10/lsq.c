/*======================================================
// ��������lsq
// ������������С�������
// ���������x ָ����n���������ݵ������ָ��
//           y ָ����n�����ĺ���ֵ�������ָ��
//           n ���ĸ���
//           p ָ����pp����϶���ʽϵ���������ָ��
//           pp ��϶���ʽ����+1
//           s ָ�������ָ�룬���4�����ݣ����ص������ǣ� ����ƽ����,
//             ���ľ���ֵ�����ֵ�����ľ���ֵ֮��,x0��ƽ��ֵ
// ����ֵ��  ���͡�����ϳɹ��򷵻�1,���򷵻�0
=========================================================*/
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int lsq(x, y, n, p, pp, s)

double *x, *y, *p, *s;
int n, pp;
{
int i, j, k;
double a, b, d0, d1, d2, c, t;
double *q0, *q1, *q2, *x0;                              /* �����������ʽQ��ϵ��*/
double *q0y, *q1y, *q2y;                          /* �����������ʽQ�ڸ����ϵ�ֵ*/
if(!(
x &&y
&&
p &&s
))                           /* �������ָ���Ƿ�Ϊ��*/
{
printf("Pointer is Null\n");
return(0);
}
q0 = (double *) malloc(pp * sizeof(double));          /* ����ռ䲢����Ƿ�ɹ�*/
q1 = (double *) malloc(pp * sizeof(double));
q2 = (double *) malloc(pp * sizeof(double));
if(!(
q0 &&q1
&& q2))
{
free(q0);
free(q1);
free(q2);
printf("Memory alloc Failed\n");
return(0);
}
x0 = (double *) malloc(n * sizeof(double));
q0y = (double *) malloc(n * sizeof(double));          /* ����ռ䲢����Ƿ�ɹ�*/
q1y = (double *) malloc(n * sizeof(double));
q2y = (double *) malloc(n * sizeof(double));
if(!(
x &&q0y
&&
q1y &&q2y
))
{
free(x);
free(q0y);
free(q1y);
free(q2y);
printf("Memory alloc Failed\n");
return(0);
}
t = 0.0;
for(
k = 0;
k<n;
k++)
t = t + x[k] / n;
s[3] =
t;
for(
k = 0;
k<n;
k++)
x0[k] = x[k]-
t;
for(
i = 0;
i<pp;
i++)                               /* ���ֵ*/
{
q0[i] = 0.0;
q1[i] = 0.0;
q2[i] = 0.0;
p[i] = 0.0;
}
for(
k = 0;
k<n;
k++)
q0y[k] = 1.0;
q0[0] = 1;                                        /* Q0��ϵ��*/
c = 0.0;
d0 = n;
for(
k = 0;
k<n;
k++)                                /* ����c0*/
c = c + y[k] / d0;
p[0] =
c;                                      /* ��϶���ʽP(x)��ϵ��*/
q1[0] = 0.0;
q1[1] = 1.0;                                      /* Q1��ϵ��*/
d1 = 0.0;
c = 0.0;
for(
k = 0;
k<n;
k++)                                /* ����d1��c1*/
{
t = x0[k];
q1y[k] =
t;                                     /* Q1�����ݵ��ϵ�ֵ*/
d1 = d1 + t * t;
c = c + t * y[k];
}
c = c / d1;
p[0] = p[0]+
c *q1[0];                             /* ������϶���ʽ*/
p[1] = p[1]+
c *q1[1];
for(
i = 2;
i<pp;
i++)
{
a = 0.0;
for(
k = 0;
k<n;
k++)
a = a + x0[k] * q1y[k] * q1y[k];
a = a / d1;                                      /* alphai*/
b = d1 / d0;                                     /* beta*/
d2 = 0;
c = 0;
for(
k = 0;
k<n;
k++)                             /* ����Qi�ĺ���ֵ��c,d*/
{
t = (x0[k] - a) * q1y[k] - b * q0y[k];
q2y[k] =
t;
d2 = d2 + t * t;
c = c + t * y[k];
}
c = c / d2;
q2[0] = -
a *q1[0]
-
b *q0[0];                      /* ����Qi��ϵ��*/
p[0] = p[0] +
c *q2[0];                         /* ����P(x)��ϵ��*/
for(
j = 1;
j<=
i;
j++)
{
q2[j] = q1[j-1]-
a *q1[j]
-
b *q0[j];
p[j] = p[j]+
c *q2[j];
}
d0 = d1;
d1 = d2;                              /* ѭ��ʹ�ñ���*/
for(
k = 0;
k<n;
k++)                             /* ѭ��ʹ������*/
{
q0y[k] = q1y[k];
q1y[k] = q2y[k];
}
for(
j = 0;
j<=
i;
j++)
{
q0[j] = q1[j];
q1[j] = q2[j];
}
}
s[0]=0.0; s[1]=0.0; s[2]=0.0;
for(
i = 0;
i<n;
i++)
{
t = p[pp - 1];
for(
k = pp - 2;
k>=0; k--)
t = p[k] + t * x0[i];
t = t - y[i];
if(
fabs(t)
>s[2])
s[2]=
fabs(t);
s[0] = s[0]+
t *t;
s[1] = s[1]+
fabs(t);
}
free(q0);
free(q1);
free(q2);                  /* �ͷſռ�*/
free(x);
free(q0y);
free(q1y);
free(q2y);
return(1);
}
