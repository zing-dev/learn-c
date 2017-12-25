/*======================================================
//��������ttest.c
//������������t�ֲ����������ֲ��ľ�ֵ�Ƿ��������Բ���(������ͬ)
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

int ttest(a, na, b, nb, alpha)
double *a, *b, alpha;
int na, nb;
{
int j = 0;
double meana = 0, meanb = 0, vara = 0, varb = 0;    //��ʼ��
double sd, t, x, p;
int v;
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
vara+=(a[j]-meana)*(a[j]-meana);    //����һ�ķ���*na
for(
j = 0;
j<nb;
j++)
varb+=(b[j]-meanb)*(b[j]-meanb);    //�������ķ���*nb

v = na + nb - 2;
sd = sqrt((1.0 / na + 1.0 / nb) / (double) v * (vara + varb));//����sd
t = (meana - meanb) / sd;                        //����t
x = v / (v + t * t);
p = beta2(v / 2, 0.5, x, eps);                    //�����
return(p<=alpha);
}

	

