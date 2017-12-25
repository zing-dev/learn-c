/*======================================================
//��������ftest.c
//������������f�ֲ����������ֲ��ķ����Ƿ��������Բ���
//���������a�����������һ������ֵ��
//	    na������һ�ĸ�����
//          b�������������������ֵ��
//	    nb���������ĸ�����
//	    alpha�������Ա�׼��
//����ֵ��1����������0����������
=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "beta2.c"

int ftest(a, na, b, nb, alpha)
double *a, *b, alpha;
int na, nb;
{
int j = 0;
double meana = 0, meanb = 0, vara = 0, varb = 0;    //��ʼ��
double f, v1, v2, q1;
double eps = 0.00001;
for(
j = 0;
j<na;
j++)
meana+=a[j];
meana = meana / na;                            //��������һ��ֵ
for(
j = 0;
j<nb;
j++)
meanb+=b[j];
meanb = meanb / nb;                            //������������ֵ
for(
j = 0;
j<na;
j++)
vara+=(a[j]-meana)*(a[j]-meana);    //����һ�ķ���
for(
j = 0;
j<nb;
j++)
varb+=(b[j]-meanb)*(b[j]-meanb);    //�������ķ���
vara = vara / (na - 1);
varb = varb / (nb - 1);
v1 = na - 1;
v2 = nb - 1;
if(vara<varb)                        /* ѡ����һ������ĸ*/
{
f = vara / varb;
v1 = na - 1;
v2 = nb - 1;
}
else
{
f = varb / vara;
v1 = nb - 1;
v2 = na - 1;
}
q1 = 2.0 * beta2(0.5 * v2, 0.5 * v1, v2 / (v2 + v1 * f));  /* ���ò���ȫ������������*/
if(q1 > 1.0)
q1 = 2.0 - q1;
return(q1<=alpha);
}	

