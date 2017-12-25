/*======================================================
//��������jcb2
//�����������Գƾ���������ֵ
//���������a   ָ���ŶԳƾ����ָ��
n   �������
u   ���ص�����ֵ
eps ����Ҫ�������ж�Ԫ���Ƿ�Ϊ0
itmax ����������
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int jcb2(a, n, u, eps, itmax)

double *a, *u, eps;
int n, itmax;
{
int i, j, p, q, it, flag;
double sint, cost, sin2t, cos2t, tmp, r, t1, t2, t3;
r = 0.0;
for(
i = 1;
i<n;
i++)
for(
j = 0;
j<i;
j++)
r = r + a[i * n + j] * a[i * n + j];
r = 2.0 * r;                               /* �����ʼ��r*/
it = 0;
while((it<itmax) && (r>eps))
{
it++;
flag = 1;
r = r / n;
while(flag==1)
{
p = 0;
q = 0;
for(
i = 1;
i<n;
i++)                  /* Ѱ�Ҵ���r�ķǶԽ���Ԫ��*/
for(
j = 0;
j<i;
j++)
{
tmp = fabs(a[i * n + j]);
if(tmp>r)
{
p = i;
q = j;
j = i;
i = n;                /* �ҵ���һ������ֹɨ��*/
}
}
if(p == 0)                         /* û�д���r�ķǶԽ���Ԫ�أ��˴�ɨ�����*/
flag = 0;
else
{
sint = 2 * a[p * n + q];
cost = a[q * n + q] - a[p * n + p];
sin2t = sint / (sqrt(sint * sint + cost * cost));      /* ����sin(2 theta)*/
if(cost<0.0)
sin2t = -sin2t;
cos2t = sqrt(1.0 - sin2t * sin2t);
sint = sin2t / (sqrt(2 * (1.0 + cos2t)));     /* ����givens����Ԫ��*/
cost = sqrt(1.0 - sint * sint);
tmp = a[p * n + p];                   /* ���Ʊ任*/
t1 = tmp * cost * cost;
t2 = a[q * n + q] * cost * cost;
t3 = a[p * n + q] * sin2t;
a[
p *n
+p] = t1 + a[
q *n
+q] - t2 -
t3;
a[
q *n
+q] = tmp - t1 + t2 +
t3;
a[
p *n
+q] = 0.0;
a[
q *n
+p] = 0.0;
for(
j = 0;
j<n;
j++)               /* ��p�к͵�q�еı任*/
if((j!=p)&&(j!=q))
{
tmp = a[p * n + j];
a[
p *n
+j] =
tmp *cost
-a[
q *n
+j]*
sint;
a[
q *n
+j] =
tmp *sint
+a[
q *n
+j]*
cost;
}
for(
i = 0;
i<=n-1; i++)           /* �öԳ��Կ���õ�p�к͵�q��*/
if((i!=p)&&(i!=q))
{
a[
i *n
+p] = a[
p *n
+i];
a[
i *n
+q] = a[
q *n
+i];
}
}
}
}
for(
i = 0;
i<n;
i++)                              /* ��������ֵ*/
u[i] = a[
i *n
+i];
return(it<itmax);                               /* ��it<itmax����˵�������ɹ�*/
}