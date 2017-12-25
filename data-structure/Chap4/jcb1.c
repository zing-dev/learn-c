/*======================================================
//��������jcb1
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

int jcb1(a, n, u, eps, itmax)

double *a, *u, eps;
int n, itmax;
{
int i, j, p, q, it;
double sint, cost, sin2t, cos2t, d, tmp, t1, t2, t3;
it = 0;
while(it<itmax)
{
it++;
d = 0.0;
for(
i = 1;
i<n;
i++)                  /* Ѱ�Ҿ���ֵ����Ԫ��*/
for(
j = 0;
j<i;
j++)
{
tmp = fabs(a[i * n + j]);
if(tmp>d)
{
d = tmp;
p = i;
q = j;
}
}
if(d<eps)                         /* �Ѿ������ɶԽ��󣬴�ʱ�������*/
{
for(
i = 0;
i<n;
i++)              /* ȡ������ֵ*/
u[i] = a[
i *n
+i];
return(it);
}
sint = 2 * a[p * n + q];
cost = a[q * n + q] - a[p * n + p];
sin2t = sint / (sqrt(sint * sint + cost * cost));
if(cost<0.0)
sin2t = -sin2t;                   /* ����sin(2 theta)*/
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
return(0);
}

