/*======================================================
//��������eulerinvh
//����������������ŷ���㷨��΢�ַ�����ĳ�ֵ����
//���������*y�� ָ������ֵ�Լ���������ֵ��ָ��n*(m+1)��
//          n���������������f��Ŀ�꺯���ļ��㣩
//          h����������m����������a��������㣩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int eulerinvh(y, n, f, h, m, a)

double *y, (*f)(), h, a;
int n, m;
{
double *F, x;
int k = 0, i;
F = (double *) malloc(sizeof(double) * n);     /* ΢�ַ��̱��ʽ��ֵ*/
if(F==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
do
{
x = a + k * h;
f(&y[k * n], F, x
);                      /* ����΢�ַ��̱��ʽ��ֵ*/
for(
i = 0;
i<n;
i++)
y[(k+1)*n+i]=y[
k *n
+i]+
h *F[i];    /* ����˴��ĺ���ֵ*/
k++;
}
while(k<m);
free(F);
return (1);
}
