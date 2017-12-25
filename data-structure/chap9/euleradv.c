/*======================================================
//��������euleradv
//�����������Ľ���ŷ���㷨��΢�ַ�����ĳ�ֵ����
//���������*y�� ָ������ֵ�Լ���������ֵ��ָ��n*(m+1)��
//          n���������������f��Ŀ�꺯���ļ��㣩
//          h����������m����������a��������㣩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int euleradv(y, n, f, h, m, a)

double *y, (*f)(), h, a;
int n, m;
{
double *y1, *y2, x;
int k = 0, i;
y1 = (double *) malloc(sizeof(double) * n);   /* ΢�ַ���Ԥ��ֵ*/
y2 = (double *) malloc(sizeof(double) * n);
if(y1==NULL||y2==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
do
{
x = a + k * h;
f(&y[k * n], y1, x
);                   /* Ԥ��*/
for(
i = 0;
i<n;
i++)
y1[i]=y[
k *n
+i]+
h *y1[i];
f(y1, y2, x
+h);                      /* ��Ԥ��*/
for(
i = 0;
i<n;
i++)
y2[i]=y[
k *n
+i]+
h *y2[i];
for(
i = 0;
i<n;
i++)
y[(k+1)*n+i]=(y1[i]+y2[i])/2;  /* ����˴��ĺ���ֵ*/
k++;
}
while(k<m);
free(y1);
free(y2);
return (1);
} 
