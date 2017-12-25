/*=============================================================
// �� �� ����dct (x,n,y)
// ������������ɢ���ұ任
// ���������x���任��ʼֵ����n��ϵ����������y���任�����У�
// �� �� ֵ���������֡�����ɹ��򷵻�1�����򷵻�0
//==============================================================*/
#include"stdio.h"
#include"math.h"
#include"c_comp.c"

int dct(x, n, y)
int n;
double *x, *y;
{
int i, j, k, nn;
double t;
struct c_comp wn, w, t2;
struct c_comp *x1, *y1;
x1 = (struct c_comp *) malloc(n * sizeof(struct c_comp));
y1 = (struct c_comp *) malloc(n * sizeof(struct c_comp));
k = log(n - 0.5) / log(2.0) + 1;                  /* ���k��ʹ2^k>=n>2^(k-1) */
nn = 1;                                    /* �ж�n�Ƿ���2�������ݣ����ǵĻ��˳�����*/
for(
i = 0;
i<k;
i++)
nn = nn << 1;
if(nn != n)
{
printf("n should be 2^k.\n");
free(x1);
free(y1);
return(0);
}
k = n >> 1;
for(
i = 0;
i<k;
i++)                       /* ��x�������� , ǰ���*/
{
x1[i].
rmz = x[2 * i];
x1[i].
imz = 0.0;
}
for(
i = k;
i<n;
i++)                       /* ��x�������� ,����*/
{
x1[i].
rmz = x[2 * (n - i) - 1];
x1[i].
imz = 0.0;
}
j = fft(x1, n, y1);                         /* �����Ӻ������㸵��Ҷ�任*/
t = 1.0 / sqrt(n);
y[0] =
t *y1[0]
.
rmz;
t = sqrt(2) * t;
wn.
rmz = cos(3.1415926 / 2 / n);
wn.
imz = sin(-3.1415926 / 2 / n);
w.
rmz = 1.0;
w.
imz = 0.0;
for(
i = 1;
i<n;
i++)
{
c_comp_product(&wn, &w, &w
);      /* w��wn��ˣ��������w�У���k���ۺ�ʱ��w����wn^k*/
c_comp_product(&w, &y1[i], &t2
);
y[i] =
t *t2
.
rmz;                     /* ʵ��Ϊ���*/
}
free(x1);
free(y1);
return(j);
}