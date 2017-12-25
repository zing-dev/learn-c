/*=============================================================
// �� �� ����ifft (y,n,x)
// ��������������Ҷ��任
// ���������y�����任�����У���n��y�ĳ��ȣ���x���任������У�
// �� �� ֵ���������֡�����ɹ��򷵻�1�����򷵻�0
//==============================================================*/
#include"stdio.h"
#include"math.h"
#include"c_comp.c"

int ifft(y, n, x)
int n;
struct c_comp *x, *y;
{
int i, j, k, nn;

int ifft1(struct c_comp *y, int n, struct c_comp *x); /* ��������һ��Ҫ���õ��Ӻ���*/
k = log(n - 0.5) / log(2.0) + 1;                      /* ���log2(n)*/
nn = 1;
for(
i = 0;
i<k;
i++)                              /* ��������Ƿ���2����������*/
nn = nn << 1;
if(nn != n)
{
printf("(ifft)n should be 2^k.\n");
return(0);
}
j = ifft1(y, n, x);                               /* �����Ӻ��������ͷ����еĲ���*/
if(j)
{
for(
i = 0;
i<n;
i++)                               /* ���Ӻ������صĽ������n*/
{
x[i].rmz /=
n;
x[i].imz /=
n;
}
}
return(j);
}

int ifft1(y, n, x)
int n;
struct c_comp *x, *y;
{
int i, j, k;
struct c_comp wn, w, t;
struct c_comp *x0, *x1, *y0, *y1;
if(n==1)                                          /* n=1ʱ��ΨһԪ��x��y���*/
{
x[0].
rmz = y[0].rmz;
x[0].
imz = y[0].imz;
return(1);
}
k = n >> 1;                                 /*k��n��һ�룬��������С��ģ�������ռ�Ĵ�С*/
x0 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
x1 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
y0 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
y1 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
if((x0==NULL)||(x1==NULL)||(y0==NULL)||(y1==NULL))
{
printf("(ifft)memory xlloc fxiled.\n");
return(0);
}
for(
i = 0;
i<k;
i++)                             /* ������ֳ�����*/
{
j = 2 * i;
y0[i].
rmz = y[j].rmz;
y0[i].
imz = y[j].imz;
y1[i].
rmz = y[j + 1].rmz;
y1[i].
imz = y[j + 1].imz;
}
i = ifft1(y0, k, x0);                           /* �����ηֱ����*/
j = ifft1(y1, k, x1);
if(
i &&j
)                                    /* ���������ɹ����������ֽ��ۺ�����*/
{
wn.
rmz = cos(2 * PI / n);
wn.
imz = sin(2 * PI / n);
w.
rmz = 1.0;
w.
imz = 0.0;

for(
i = 0;
i<k;
i++)
{
c_comp_product(&w, &x1[i], &t
);
c_comp_plus(&x0[i], &t, &x[i]
);               /* һ��һ������������е��ۺ�*/
c_comp_sub(&x0[i], &t, &x[i + k]
);
c_comp_product(&wn, &w, &w
);     /* w��wn��ˣ��������w�У���k���ۺ�ʱ��w����wn^k*/
}
}
free(y0);
free(y1);
free(x0);
free(x1);
return(1);
}
