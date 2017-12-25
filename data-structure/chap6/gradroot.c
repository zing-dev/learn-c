/*======================================================
//��������gradroot
//����������������Է������һ��ʵ��
//���������*x0��ָ�������ֵ����ֵ��ָ�룩
//          n�������������
//          f��Ŀ�꺯���ļ�����ƫ�����ļ��㣩
//          eps������Ҫ��
//          max��������������
//����ֵ��0������ʧ�ܣ���1�������ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int gradroot(x0, n, f, eps, max)

double *x0, (*f)(), eps;
int n, max;
{
double F, *FD, D, lam;
int i, num = 0;
FD = (double *) malloc(sizeof(double) * n);   /* ����ռ䲢����Ƿ�ɹ�*/
if(FD==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
do
{
num++;
F = f(x0, FD);                         /* ����Ŀ�꺯����ƫ����*/
if(F>eps)
{
D = 0;
for(
i = 0;
i<n;
i++)
D = D + FD[i] * FD[i];            /* ����D��ϵ��lamda*/
lam = F / D;
for(
i = 0;
i<n;
i++)
x0[i]=x0[i]-
lam *FD[i];      /* ��ֵ*/
}

else
return(1);
}while(num<max);
if(num==max)
return (0);                         /* ����ʧ��*/
else
return (1);                         /* �����ɹ�*/
}


