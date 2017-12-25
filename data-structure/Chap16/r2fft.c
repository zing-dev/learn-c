/*=============================================================
// �� �� ����r2fft (x,n,y)
// ��������������ʵ������ͬʱ���и���Ҷ�任����Ҫfft������֧�֡�
// ���������x���任��ʼֵ����n��ϵ����������y���任�����У�
// �� �� ֵ���������֡�����ɹ��򷵻�1�����򷵻�0
//==============================================================*/
#include"stdio.h"
#include"math.h"
#include"c_comp.c"

int r2fft(x1, x2, n, y1, y2)
int n;
double *x1, *x2;
struct c_comp *y1, *y2;
{
int i, j, k, nn;
struct c_comp *x, *y;

k = log(n - 0.5) / log(2.0) + 1;                  /* ���k��ʹ2^k>=n>2^(k-1) */
nn = 1;                                /* �ж�n�Ƿ���2�������ݣ����ǵĻ��˳�����*/
for(
i = 0;
i<k;
i++)
nn = nn << 1;
if(nn != n)
{
printf("n should be 2^k.\n");
return(0);
}
x = (struct c_comp *) malloc(n * sizeof(struct c_comp));
y = (struct c_comp *) malloc(n * sizeof(struct c_comp));
for(
i = 0;
i<n;
i++)                          /* ���*/
{
x[i].
rmz = x1[i];
x[i].
imz = x2[i];
}
fft(x, n, y
);                                     /* ���и���Ҷ�任*/
y1[0].
rmz = y[0].rmz;
y1[0].
imz = 0.0;
y2[0].
rmz = y[0].imz;                           /* �����һ����*/
y2[0].
imz = 0.0;
for(
k = 1;
k<=n/2; k++)
{
j = n - k;
y1[k].
rmz = 0.5 * (y[k].rmz + y[j].rmz);      /* ���ǰ�벿��*/
y1[k].
imz = 0.5 * (y[k].imz - y[j].imz);
y2[k].
rmz = 0.5 * (y[k].imz + y[j].imz);
y2[k].
imz = -0.5 * (y[k].rmz - y[j].rmz);
y1[j].
rmz = y1[k].rmz;                     /* �����벿��*/
y1[j].
imz = -y1[k].imz;
y2[j].
rmz = y2[k].rmz;
y2[j].
imz = -y2[k].imz;
}
free(x);
free(y);
return(1);
}