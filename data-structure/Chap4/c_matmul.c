#include "stdio.h"
#include "stdlib.h"
#include "c_comp.c"                /* ��Ҫ���ø���������㷨*/

/*======================================================
//��������cmat_mul
//�������������������������
//���������a(�����) b(�Ҿ���)  c(�������)
            m(���������) p(���������) n(�Ҿ�������)
//����ֵ�����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
int c_matmul(a, b, m, p, n, c)
struct c_comp *a, *b, *c;
int m, p, n;
{
int i, j, k;
struct c_comp tmp1, tmp2;

if(!(m>0 && p>0 && n>0))            /* ����������Ľ���*/
{
printf("Err:(c_mat_mul)Dimension of a matrix is incorrect\n");
return(0);
}
if(a == NULL || b == NULL || c == NULL)    /* �������ָ���Ƿ�Ϊ��*/
{
printf("Err:(c_mat_mul)The matrix pointer is NULL\n");
return(0);
}

for(
i = 0;
i<m;
i++)                /* ѭ����������c�е�ÿ��Ԫ��*/
for(
j = 0;
j<n;
j++)
{
tmp1.
rmz = 0.0;            /* ��ֵ�ȴ��븴��ʱ������*/
tmp1.
imz = 0.0;

for(
k = 0;
k<p;
k++)            /* ѭ���ۼ�*/
{
c_comp_product(&a[i * m + k], &b[k * m + j], &tmp2
);
c_comp_plus(&tmp1, &tmp2, &tmp1
);
}
c[
i *n
+j].
rmz = tmp1.rmz;        /* ������Ľ���������c��*/
c[
i *n
+j].
imz = tmp1.imz;
}
return(1);
}
