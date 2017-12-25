/*======================================================
//��������rungekuttainvh
//�����������������Ľ���������㷨��΢�ַ�����ĳ�ֵ����
//���������*y�� ָ������ֵ�Լ���������ֵ��ָ��n*(m+1)��
//          n���������������f��б�ʵļ��㣩
//          h����������m����������a��������㣩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int rungekuttainvh(y, n, f, h, m, a)

double *y, (*f)(), h, a;
int n, m;
{
double *k1, *k2, *k3, *k4, *ytemp, x;
int k = 0, i;
k1 = (double *) malloc(sizeof(double) * n);        /* ΢�ַ���б��*/
k2 = (double *) malloc(sizeof(double) * n);
k3 = (double *) malloc(sizeof(double) * n);
k4 = (double *) malloc(sizeof(double) * n);
ytemp = (double *) malloc(sizeof(double) * n);
if(k1==NULL||k2==NULL||k3==NULL||k4==NULL||ytemp==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
do
{
x = a + k * h;
f(&y[k * n], k1, x
);                           /* k1*/
for(
i = 0;
i<n;
i++)
ytemp[i]=y[
k *n
+i]+
h *k1[i]
/2.0;
f(ytemp, k2, x
+h/2.0);                       /* k2*/
for(
i = 0;
i<n;
i++)
ytemp[i]=y[
k *n
+i]+
h *k2[i]
/2.0;
f(ytemp, k3, x
+h/2.0);                       /* k3*/
for(
i = 0;
i<n;
i++)
ytemp[i]=y[
k *n
+i]+
h *k3[i];
f(ytemp, k4, x
+h);                           /* k4*/
for(
i = 0;
i<n;
i++)                           /* ����˴��ĺ���ֵ*/
y[(k+1)*n+i]=y[
k *n
+i]+h/6.0*(k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i]);
k++;
}
while(k<m);
free(k1);
free(k2);
free(k3);
free(k4);
free(ytemp);
return (1);
}

 