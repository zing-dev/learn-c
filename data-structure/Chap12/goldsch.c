/*======================================================
// ��������goldsch
// �����������ƽ�ָ���������ֵ
// ���������a ��ʼ����Ķ˵�
//           b ��ʼ������м��
//           c ��ʼ�������һ���˵�
//           f ����ָ��
//           xopt ָ�룬ָ��ֵ�������
//         eps �����޶�
// ����ֵ��  �����ļ�Сֵ
=========================================================*/

#include "stdio.h"
#include "math.h"

#define G2 0.38196601

double goldsch(a, b, c, f, xopt, eps)

double a, b, c, eps;

double (*f)(double);

double *xopt;
{
double f0, f1, f2, f3, t;
if(
fabs(c
-b) >
fabs(b
-a))            /* �ڽϴ��һ������t*/
t = b + G2 * (c - b);
else
{
t = b;
b = b - G2 * (b - a);
}
f1 = (*f)(b);
f2 = (*f)(t);
while(
fabs(c
-a) >
eps *(fabs(b)
+
fabs(t)
))
{
if(f2>f1)                         /* ������Ϊ[a b t]*/
{
c = t;                        /* ����c*/
t = b;                        /* ����b��t*/
b = b - G2 * (b - a);
f3 = f2;
f2 = f1;
f1 = (*f)(b);
}
else                              /* ������Ϊ[b t c]*/
{
a = b;                         /* ����a*/
b = t;
t = t + G2 * (c - t);                /* ������t*/
f0 = f1;
f1 = f2;
f2 = (*f)(t);
}
}
if(f1<f2){                             /* ���ؽϺõ�һ��ֵ*/
*
xopt = b;
return(f1);
}
else
{
*
xopt = t;
return(f2);
}
}
