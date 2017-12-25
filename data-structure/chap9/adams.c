/*======================================================
//��������adams
//��������������ķ˹Ԥ��У������΢�ַ�����ĳ�ֵ����
//���������*y�� ָ������ֵ�Լ���������ֵ��ָ��n*(m+1)
//          n���������������f��б�ʵļ��㣩
//          h����������m����������a��������㣩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include "rungekuttainvh.c"

int adams(y, n, f, h, m, a)
double *y, (*f)(), h, a;
int n, m;
{
double *f1, *f2, *f3, *f4, *f5, *temp, *ytemp, x;
int k = 3, i;
f1 = (double *) malloc(sizeof(double) * n);               /* ΢�ַ���б��*/
f2 = (double *) malloc(sizeof(double) * n);
f3 = (double *) malloc(sizeof(double) * n);
f4 = (double *) malloc(sizeof(double) * n);
f5 = (double *) malloc(sizeof(double) * n);
ytemp = (double *) malloc(sizeof(double) * n);

if(f1==NULL||f2==NULL||f3==NULL||f4==NULL||f5==NULL||ytemp==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
rungekuttainvh(y, n, f, h,
3,a);                        /* ������-����������ǰ4����ֵ*/
{
x = a + k * h;
f(&y[(k - 3) * n], f1, x
-3*h);                        /* x(k-3)����f*/
f(&y[(k - 2) * n], f2, x
-2*h);                        /* x(k-2)����f*/
f(&y[(k - 1) * n], f3, x
-h);                          /* x(k-1)����f*/
f(&y[k * n], f4, x
);                                /* xk����f*/
for(
i = 0;
i<n;
i++)                                /* Ԥ��*/
ytemp[i]=y[
k *n
+i]+h/24.0*(55.0*f4[i]-59.0*f3[i]+37.0*f2[i]-9.0*f1[i]);
f(ytemp, f5, x
+h);                                /* x(k+1)����f*/
for(
i = 0;
i<n;
i++)                                /* У��*/
y[(k+1)*n+i]=y[
k *n
+i]+h/24.0*(9.0*f5[i]+19.0*f4[i]-5.0*f3[i]+f2[i]);
k++;
}
while(k<m)                                          /* ѭ��*/
{
x = a + k * h;
temp = f1;
f1 = f2;
f2 = f3;
f3 = f4;
f4 = temp;
f(&y[k * n], f4, x
);                                /* f4*/
for(
i = 0;
i<n;
i++)
ytemp[i]=y[
k *n
+i]+h/24.0*(55.0*f4[i]-59.0*f3[i]+37.0*f2[i]-9.0*f1[i]);
f(ytemp, f5, x
+h);                                /* k3*/
for(
i = 0;
i<n;
i++)
y[(k+1)*n+i]=y[
k *n
+i]+h/24.0*(9.0*f5[i]+19.0*f4[i]-5.0*f3[i]+f2[i]);
k++;
}
free(f1);
free(f2);
free(f3);
free(f4);
free(f5);
free(ytemp);
return (1);
}

