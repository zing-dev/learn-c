/*=============================================================
// �� �� ����fft (x,n,y)
// ������������ɢ����Ҷ�任
// ���������x���任��ʼֵ����n��ϵ����������y���任�����У�
// �� �� ֵ���������֡�����ɹ��򷵻�1�����򷵻�0
//==============================================================*/
#include"stdio.h"
#include"math.h"
#include"c_comp.c"

int fft(y, n, x)
int n;
struct c_comp *x, *y;
{
int i, j, k, nn;

int fft0(struct c_comp *x, int n, struct c_comp *y);    /* ��ΪҪ�ݹ���ã�����������*/
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
j = fft0(y, n, x);                               /* �����Ӻ������㸵��Ҷ�任*/
return(j);
}

int fft0(x, n, y)
int n;
struct c_comp *x, *y;
{
int i, j, k;
struct c_comp wn, w, t;
struct c_comp *x0, *x1, *y0, *y1;
if(n==1)
{                                    /* �����г���Ϊ1ʱ������Ҷ�任��������*/
y[0].
rmz = x[0].rmz;
y[0].
imz = x[0].imz;
return(1);
}
k = n >> 1;                       /* k��n��һ�룬������С��ģ������Ҫ����ռ��С*/
x0 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
x1 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
y0 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
y1 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
if((x0==NULL)||(x1==NULL)||(y0==NULL)||(y1==NULL))
{
printf("memory xlloc fxiled.\n");
return(0);
}                                                  /* �����зֳ�����*/
for(
i = 0;
i<k;
i++)
{
j = 2 * i;
x0[i].
rmz = x[j].rmz;
x0[i].
imz = x[j].imz;
x1[i].
rmz = x[j + 1].rmz;
x1[i].
imz = x[j + 1].imz;
}                                                  /* �ݹ���ô˺���*/
i = fft0(x0, k, y0);
j = fft0(x1, k, y1);
if(
i &&j
)                                /* ���õ��������������ۺ�����*/
{
wn.
rmz = cos(2 * PI / n);
wn.
imz = sin(-2 * PI / n);
w.
rmz = 1.0;
w.
imz = 0.0;
for(
i = 0;
i<k;
i++)
{
/* һ��һ������������е��ۺ�*/
c_comp_product(&w, &y1[i], &t
);
c_comp_plus(&y0[i], &t, &y[i]
);
c_comp_sub(&y0[i], &t, &y[i + k]
);
c_comp_product(&wn, &w, &w
);      /* w��wn��ˣ��������w�У���k���ۺ�ʱ��w����wn^k*/
}
}
free(y0);
free(y1);
free(x0);
free(x1);
return(1);
}
