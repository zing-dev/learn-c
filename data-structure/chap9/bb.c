/*======================================================
//��������bb
//����������˫�߷���΢�ַ�����ĳ�ֵ����
//���������*y�� ָ������ֵ�Լ���������ֵ��ָ��n*(m+1)��
//          n���������������f��б�ʵļ��㣩
//          h����������m����������a��������㣩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//#include "rungekuttainvh.c"

int bb(y, n, f, h, m, a)

double *y, (*f)(), h, a;
int n, m;
{
double *f1, *f2, *f3, *p, *q, x;
int k = 1, i;
q = (double *) malloc(sizeof(double) * n);
p = (double *) malloc(sizeof(double) * n);     /* ΢�ַ���б��*/
f1 = (double *) malloc(sizeof(double) * n);
f2 = (double *) malloc(sizeof(double) * n);
f3 = (double *) malloc(sizeof(double) * n);

if(q==NULL||p==NULL||f2==NULL||f3==NULL||f1==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
rungekuttainvh(y, n, f, h,
1,a);             /* ������-����������ǰ2����ֵ*/
do
{
x = a + k * h;
f(&y[(k - 1) * n], f1, x
-h);               /* x(k-1)����f*/
f(&y[k * n], f2, x
);                     /* x(k)����f*/

for(
i = 0;
i<n;
i++)                     /* Ԥ��p*/
p[i]=-4.0*y[
k *n
+i]+5.0*y[(k-1)*n+i]+2.0*h*(2.0*f2[i]+f1[i]);
f(p, f3, x
+h);                         /* Ԥ��x(k+1)����f*/
for(
i = 0;
i<n;
i++)
{                                    /* Ԥ��c*/
q[i]=4.0*y[
k *n
+i]-3.0*y[(k-1)*n+i]+2.0*h/3.0*(f3[i]-2.0*f2[i]-2.0*f1[i]);
y[(k+1)*n+i]=0.5*(p[i]+q[i]);    /* �������ս��*/
}
k++;
}
while(k<m);                              /* ѭ��*/
free(p);
free(f2);
free(f3);
free(f1);
free(q);
return (1);
}

 
