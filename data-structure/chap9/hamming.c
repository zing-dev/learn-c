/*======================================================
//��������hamming
//��������������������΢�ַ�����ĳ�ֵ����
//���������*y�� ָ������ֵ�Լ���������ֵ��ָ��n*(m+1)��
//          n���������������f��б�ʵļ��㣩
//          h����������m����������a��������㣩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//#include "rungekuttainvh.c"

int hamming(y, n, f, h, m, a)

double *y, (*f)(), h, a;
int n, m;
{
double *c, *f1, *f2, *f3, *f4, *temp, *ptemp, *p, x;
int k = 3, i;
c = (double *) malloc(sizeof(double) * n);
p = (double *) malloc(sizeof(double) * n);      /* ΢�ַ���б��*/
f1 = (double *) malloc(sizeof(double) * n);
f2 = (double *) malloc(sizeof(double) * n);
f3 = (double *) malloc(sizeof(double) * n);
f4 = (double *) malloc(sizeof(double) * n);
ptemp = (double *) malloc(sizeof(double) * n);

if(c==NULL||p==NULL||f2==NULL||f3==NULL||f4==NULL||f1==NULL||ptemp==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
rungekuttainvh(y, n, f, h,
3,a);              /* ������-����������ǰ4����ֵ*/

{
x = a + k * h;
f(&y[(k - 2) * n], f1, x
-2*h);              /* x(k-2)����f*/
f(&y[(k - 1) * n], f2, x
-h);                /* x(k-1)����f*/
f(&y[k * n], f3, x
);                      /* xk����f*/
for(
i = 0;
i<n;
i++)                      /* Ԥ��p*/
p[i]=y[(k-3)*n+i]+4.0*h/3.0*(2.0*f3[i]-f2[i]+2.0*f1[i]);
f(p, f4, x
+h);                          /* Ԥ��x(k+1)����f*/
for(
i = 0;
i<n;
i++)
{                                     /* Ԥ��c*/
c[i]=1.0/8.0*(9.0*y[
k *n
+i]-y[(k-2)*n+i]+3.0*
h *(f4[i]
+2.0*f3[i]-f2[i]));
y[(k+1)*n+i]=c[i]-9.0/121.0*(c[i]-p[i]);              /* �������ս��*/
}
k++;
}
while(k<m)                                /* ѭ��*/
{
x = a + k * h;
temp = f1;
f1 = f2;
f2 = f3;
f3 = temp;
f(&y[k * n], f3, x
);

for(
i = 0;
i<n;
i++)
{
ptemp[i]=y[(k-3)*n+i]+4.0*h/3.0*(2.0*f3[i]-f2[i]+2.0*f1[i]);  /* Ԥ��*/
p[i]=ptemp[i]+112.0/121.0*(c[i]-p[i]);                        /* Ԥ��*/
}
f(p, f4, x
+h);                                               /* x(k+1)����f*/
for(
i = 0;
i<n;
i++)
{
c[i]=1.0/8.0*(9.0*y[
k *n
+i]-y[(k-2)*n+i]+3.0*
h *(f4[i]
+2.0*f3[i]-f2[i]));
y[(k+1)*n+i]=c[i]-9.0/121.0*(c[i]-p[i]);
}
k++;
}
free(p);
free(f2);
free(f3);
free(f4);
free(f1);
free(ptemp);
free(c);
return (1);
}

 
