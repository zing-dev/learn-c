/*======================================================
// ��������brake
// ����������ȷ�����ڼ�ֵ������
// ���������a �����ʼ����˵㣬����ʱΪ�������˵�
//           b �����ʼ����˵㣬����ʱΪ������м��
//           c ����ʱΪ������Ҷ˵�
//           f ����ָ��
// ����ֵ��  ��
=========================================================*/

#include "stdio.h"
#include "math.h"

#define G1 0.61803399
#define GSTEP 100.0
#define TINY 1.0e-20

void brake(a, b, c, f)

double *a, *b, *c;

double (*f)(double);

{
double u, u2, fu, fa, fb, fc, tmp;
double r, q, p;                          /* ���������߲�ֵ*/

fa = (*f)(*a);
fb = (*f)(*b);
if(fb > fa)                            /* ȷ��a->b�������½���*/
{
tmp = *a;
*
a = *b;
*
b = tmp;
tmp = fa;
fa = fb;
fb = tmp;
}
*
c = (*b) + G1 * (*b - *a);                /* �������쵽��c*/
fc = (*f)(*c);
while(fb >= fc)                         /* ��ʱ��Ҫ����Ѱ������*/
{
r = (*b - *a) * (fb - fc);                 /* fb-fc>=0*/
q = (*b - *c) * (fb - fa);                 /* fb-fa <=0*/
p = (*b - *c) * q - (*b - *a) * r;           /* p<0.  q��r���*/
tmp = q - r;
if(
fabs(tmp)
< TINY)                /* ��ĸ��С*/
tmp = TINY;
u = *b - p / (2.0 * tmp);                 /* ��������ߵļ�ֵ��u*/
u2 = *b + GSTEP * (*c - *b);              /* u2������u�н�����󲽳�*/
if((*b-u)*(*c-u) < 0.0)             /* u��b ��c֮��*/
{
fu = (*f)(u);
if(fu<fc)                     /* b u cȷ��һ�����ڼ�Сֵ������*/
{
if(*b < *c)                 /* ������֤a < b < c*/
{
*
a = *b;
*
b = u;
}
else                        /* ������֤a < b < c*/
{
*
a = *c;
*
c = *b;
*
b = u;
}
return;
}
else if(fu > fb)                /* a b uȷ����һ�����ڼ�Сֵ������*/
{
if(*a<u)
*
c = u;
else
{
*
c = *a;
*
a = u;
}
return;
}
u = *c + G1 * (*c - *b);             /* ������ȷ����u����*/
fu = (*f)(u);
}
else if((*c-u)*(u2-u) < 0.0)         /* u��c��u2֮��*/
{
fu = (*f)(u);
if(fu<fc)
{
*
b = *c;
*
c = u;
u = *c + G1 * (*c - *b);
fb = fc;
fc = fu;
fu = (*f)(u);
}
}
else if((u-u2)*(*c-u2)>=0)            /* �����߸�����uֵ����ʹ��u2����*/
{
u = u2;
fu = (*f)(u);
}
else
{
u = (*c) + G1 * (*c - *b);
fu = (*f)(u);
}
*
a = *b;                               /* ����a,b,c*/
*
b = *c;
*
c = u;
fa = fb;
fb = fc;
fc = fu;
}
if(*a > *c)                         /* [a,c]���Ǵ��ڼ�Сֵ������*/
{
tmp = *a;                       /* ������ a<b<c*/
*
a = *c;
*
c = tmp;
}
return;
}
