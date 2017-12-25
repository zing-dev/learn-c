/*======================================================
//��������tutest.c
//������������t�ֲ����������ֲ��ľ�ֵ�Ƿ��������Բ���(�����ͬ)
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
//#include "beta2.c"

int tutest(a, na, b, nb, alpha)

double *a, *b, alpha;
int na, nb;
{
int j = 0;
double meana = 0, meanb = 0, vara = 0, varb = 0;    //��ʼ��
double sd, d, t, x, p, v;
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
vara = vara / ((na - 1) * na);
varb = varb / ((nb - 1) * nb);


sd = sqrt(vara + varb);//����sd
t = (meana - meanb) / sd;                        //����t
d = vara * vara / (na - 1) + varb * varb / (nb - 1);
v = (vara + varb) * (vara + varb) / d;
x = v / (v + t * t);
p = beta2(v / 2, 0.5, x, eps);                    //�����
return(p<=alpha);
}

	

