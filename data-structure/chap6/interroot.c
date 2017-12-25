/*======================================================
//��������interroot
//�������������[a,b]�����ڵķ����Է���f(x)��һ��ʵ��
//���������x0��������ֵ�Լ�������ֵ�ĳ�ֵָ�룩
//          ab��δ��ѡΪ��ֵ������˵㣩
//          f�������Է�����˺�����
//          eps������Ҫ��
//          max��������������
//����ֵ��0������ʧ�ܣ�1�������ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int interroot(x0, ab, f, eps, max)

double *x0, ab, (*f)(), eps;
int max;
{
double x, dis;
double y0, yd, yab = f(ab);
int num = 0;


do
{
y0 = f(*x0);                 /* ���㺯��ֵ*/
yd = (*x0 - ab) / (y0 - yab);    /* ���㺯������ֵ�õ���ֵ*/
x = *x0 - yd * y0;             /* �����µ�xֵ*/
num++;
dis = fabs(x - *x0);         /* ���㾫��*/
if(
dis< fabs(y0)
)
dis = fabs(y0);
printf("%1.7f    %1.7f    %1.7f\n",*x0,x,dis);
*
x0 = x;
}
while(dis>
eps &&num<max
);     /* �жϵ����Ƿ����*/
if(num==max)
return (0);              /* ����ʧ��*/
else
return (1);              /* �����ɹ�*/
}

