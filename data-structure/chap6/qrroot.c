/*======================================================
//��������qrroot
//����������QR���������ʽ����ȫ��ʵ��
//���������a   ָ���Ŷ���ʽϵ����ָ�루�������У�
			n   ����ʽ����
			u   ���صĸ���ʵ��
			v   ���صĸ����鲿
			eps ����Ҫ�������ж�Ԫ���Ƿ�Ϊ0
			itmax ����������
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "mhdqr.c"

int qrroot(a, n, u, v, eps, itmax)
double *a, *u, *v, eps;
int n, itmax;
{
int i;
double *H;
H = (double *) malloc(sizeof(double) * n * n);    /* ���ɵ���H����*/
for(
i = 0;
i<n;
i++)
H[i]=-1.0*a[i+1]/a[0];                /* ��һ��*/
for(
i = n;
i<n *n;
i++)
H[i]=0.0;                               /* ����Ϊ0*/
for(
i = 1;
i<n;
i++)
H[
i *n
+i-1]=1.0;                         /* �ζԽ���Ϊ1*/
return(
mhdqr(H, n, u, v, eps, itmax
));         /* ������H����������ֵ�ĺ���*/
}



