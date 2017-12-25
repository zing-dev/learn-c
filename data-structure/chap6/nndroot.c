/*======================================================
//��������nndroot
//����������������Է������һ��ʵ��
//���������*x0��ָ�������ֵ����ֵ��ָ�룩��
//           n���������������f�� �����Է��̵ļ��㣩
//           eps������Ҫ�󣩣�max��������������
//           h�������е�΢С��������t������ϵ����
//����ֵ��0������ʧ�ܣ���1�������ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#include"r_gaus.c"

int nndroot(x0, n, f, eps, max, h, t)
double *x0, eps, h, t;

void (*f)();

int n, max;
{
double *f0, *fi, *fx, *dl, dis, sum;
int i, num = 0;
f0 = (double *) malloc(sizeof(double) * n);
fx = (double *) malloc(sizeof(double) * n);
fi = (double *) malloc(sizeof(double) * n * n);
dl = (double *) malloc(sizeof(double) * n);

if(f0==NULL||fx==NULL||fi==NULL||dl==NULL)
{
printf("memory alloc failed.\n");
return(0);
}

do
{
num++;
f(x0, f0, fi, h
);                        /* ���㷽����ֵ�Լ�ƫ��h���ֵ*/

dis = 0;
for(
i = 0;
i<n;
i++)
{
if(
fabs(f0[i])
>dis)
dis = fabs(f0[i]);              /* ����max���̵�ֵ*/
}
if(dis>eps)                           /* �����㾫�ȣ���������*/
{
if(
r_gaus(fi, f0, fx, n,
1e-8)==0)    /* ���ø�˹��ȥ���������Է�����*/
return(0);
else
{
sum = 0;
for(
i = 0;
i<n;
i++)
sum = fx[i] + sum;
sum = h / (1 - sum);

for(
i = 0;
i<n;
i++)
{
dl[i]=fx[i]*
sum;          /* ��ֵ*/
x0[i]=x0[i]-dl[i];        /* ��ֵ*/
}
h = h * t;
}
}
else
return(1);
}
while(num<max);

free(f0);
free(fi);
free(dl);

if(num==max)
return (0);                         /* ����ʧ��*/
else
return (1);                         /* �����ɹ�*/
}
