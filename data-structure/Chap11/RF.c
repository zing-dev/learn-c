/*=============================================================
// �� �� ����RF
// ��������������һ����Բ���ֵ�ֵ
// ���������x ��ֵ���Ա���
//           y ��ֵ���Ա���
//           z ��ֵ���Ա���
// �� �� ֵ����һ����Բ���ֵ�ֵ
//==============================================================*/
#include "math.h"

double RF(x, y, z)

double x, y, z;
{
double ll, t, t1, t2, flag, eps;
double xt, yt, zt;
eps = 1.0e-30;
if(x<0||y<0||z<0||(x+y)<eps||(y+z)<eps||(x+z)<eps)         /* ����Ա�����Χ*/
{
printf("Parameters incorrect\n");
return(0.0);
}
do{
t = sqrt(x);
t1 = sqrt(y);
t2 = sqrt(z);
ll = t * (t1 + t2) + t1 * t2;
x = (x + ll) / 4.0;                                        /* ����x,y,z*/
y = (y + ll) / 4.0;
z = (z + ll) / 4.0;
t = (x + y + z) / 3.0;
xt = 1.0 - x / t;
yt = 1.0 - y / t;
zt = 1.0 - z / t;
flag = fabs(zt) > fabs(yt) ? fabs(zt) : fabs(yt);
flag = flag > fabs(xt) ? flag : fabs(xt);
}while(flag > 0.0025);                                  /* �����ֵ�����ж�xyz��ֽӽ�*/
t1 = xt * yt - zt * zt;                                        /* ��̩��չ���������ֵ*/
t2 = xt * yt * zt;
t = (1 - t1 / 10.0 + t2 / 14.0 + t1 * t1 / 24.0 - 3 * t1 * t2 / 44.0) / sqrt(t);
return(t);
}
