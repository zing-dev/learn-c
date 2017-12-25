/*======================================================
//��������mde.c
//������������ֲ��ľ�
//���������a�����������������ֵ��
//	    n������������
//          mean����ž�ֵ��
//	    adev�����ƽ���
//	    sddev����ű�׼�
//	    var����ŷ��
//	    skew�����б�
//	    kurt����ŷ�̬��
=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void mde(a, n, mean, adev, sddev, var, skew, kurt)

double *a, *mean, *adev, *sddev, *var, *skew, *kurt;
int n;
{
int j = 0;
double *dis;
dis = (double *) malloc(sizeof(double) * n); //����������ֵ�Ĳ�
*
mean = 0;
*
adev = 0;
*
sddev = 0;
*
var = 0;
*
skew = 0;
*
kurt = 0;//��ʼ��
for(
j = 0;
j<n;
j++)
*mean+=a[j];
*
mean = *mean / n;//�����ֵ
for(
j = 0;
j<n;
j++)
dis[j]=a[j]-*
mean;
for(
j = 0;
j<n;
j++)
{
*adev+=
fabs(dis[j]);//ƽ����
*var+=dis[j]*dis[j];//����
}
*
adev = *adev / n;
*
var = *var / (n - 1);
*
sddev = sqrt(*var);//��׼��
for(
j = 0;
j<n;
j++)
{
dis[j]=dis[j]/(*sddev);
*skew+=dis[j]*dis[j]*dis[j];//б��
*kurt+=dis[j]*dis[j]*dis[j]*dis[j];//��̬
}
*
skew = *skew / n;
*
kurt = *kurt / n - 3;
}