/*=============================================================
// �� �� ����RD
// �������������ڶ�����Բ���ֵ�ֵ
// ���������x ��ֵ���Ա���
//           y ��ֵ���Ա���
//           z ��ֵ���Ա���
// �� �� ֵ���ڶ�����Բ���ֵ�ֵ
//==============================================================*/
#include "math.h"

double RD(x, y, z)

double x, y, z;
{
double ll, flag, eps, s, f;
double t, t1, t2, t3, t4, t5, t6;
double xt, yt, zt;
eps = 1.0e-25;
if(x<0||y<0||(x+y)<eps||z<eps)         /* ����Ա�����Χ*/
{
printf("Parameters incorrect\n");
return(0.0);
}
s = 0.0;
f = 4.0;
do{
t1 = sqrt(x);
t2 = sqrt(y);
t3 = sqrt(z);
ll = t1 * (t2 + t3) + t2 * t3;
f = f / 4.0;
s = s + f / (sqrt(z) * (z + ll));
x = (x + ll) / 4.0;                                        /* ����x,y,z*/
y = (y + ll) / 4.0;
z = (z + ll) / 4.0;
t = (x + y + 3.0 * z) / 5.0;
xt = 1.0 - x / t;
yt = 1.0 - y / t;
zt = 1.0 - z / t;
flag = fabs(zt) > fabs(yt) ? fabs(zt) : fabs(yt);
flag = flag > fabs(xt) ? flag : fabs(xt);
}while(flag > 0.0015);                                  /* �����ֵ�����ж�xyz��ֽӽ�*/
t1 = xt * yt;                                              /* ��̩��չ���������ֵ*/
t2 = zt * zt;
t3 = t1 - t2;
t4 = t1 - 6.0 * t2;
t5 = t4 + 2 * t3;
t6 = zt;
t = (1 + t4 * (-3.0 / 14.0 + 9.0 * t4 / 88.0 - 9.0 * t5 * t6 / 52.0) +
     t6 * (t5 / 5.0 + t6 * (-9.0 * t3 / 22.0 + 3 * t1 * t6 / 26.0))) / (t * sqrt(t));
t = 3.0 * s + f * t;
return(t);
}
