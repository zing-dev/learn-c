/*======================================================
//��������newdonroot
//�������������[a,b]�����ڵķ����Է���f(x)��һ��ʵ��
//���������x0��������ֵ�Լ�������ֵ�ĳ�ֵָ�룩
//          f�������Է�����˺�����
//          fd�������Է�����˺����ĵ�������
//          eps������Ҫ�󣩣�max��������������
//����ֵ��0������ʧ�ܣ�1�������ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int newdonroot(x0, f, fd, eps, max)

double *x0, (*f)(), (*fd)(), eps;
int max;
{
double x, dis;
double y0;
double yd0;
int num = 0;
do
{
y0 = f(*x0);
yd0 = fd(*x0);          /* ���㺯��ֵ�Լ�����ֵ*/
x = *x0 - y0 / yd0;                   /* �����µ�xֵ*/
num++;
dis = fabs(x - *x0);                /* ���㾫��*/
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
);            /* �жϵ����Ƿ����*/
if(num==max)
return (0);                     /* ����ʧ��*/
else
return (1);                     /* �����ɹ�*/
}

