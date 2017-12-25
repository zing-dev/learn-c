/*=============================================================
// �� �� ����p2c (y,n,a)
// ����������������ʽ�ɵ��ʾת��Ϊϵ����ʾ
// ���������y���ṩ�ĵ�ֵ����n��y�ĳ��ȣ���a������õ��Ķ���ʽϵ����
// �� �� ֵ���������֡�����ɹ��򷵻�1�����򷵻�0
//==============================================================*/
#include"stdio.h"
#include"math.h"
#include"c_comp.c"

int p2c(y, n, a)
int n;
struct c_comp *a, *y;
{
int i, j, k, nn;

int p2c1();                          /* ��������һ��Ҫ���õ��Ӻ���*/
k = log(n - 0.5) / log(2.0) + 1;            /* ���log2(n)*/
nn = 1;
for(
i = 0;
i<k;
i++)                    /* ��������Ƿ���2����������*/
nn = nn << 1;
if(nn != n)
{
printf("(p2c)n should be 2^k.\n");
return(0);
}
j = p2c1(y, n, a);                        /* �����Ӻ��������ͷ����еĲ���*/
if(j)
{
for(
i = 0;
i<n;
i++)               /* ���Ӻ������صĽ������n*/
{
a[i].rmz /=
n;
a[i].imz /=
n;
}
}
return(j);
}

int p2c1(y, n, a)
int n;
struct c_comp *a, *y;
{
int i, j, k;
struct c_comp xn, x, t;
struct c_comp *a0, *a1, *y0, *y1;
if(n==1)                                 /* n=1ʱ��Ψһϵ��a��y���*/
{
a[0].
rmz = y[0].rmz;
a[0].
imz = y[0].imz;
return(1);
}
k = n >> 1;                                /*k��n��һ�룬��������С��ģ�������ռ�Ĵ�С*/
a0 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
a1 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
y0 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
y1 = (struct c_comp *) malloc(k * sizeof(struct c_comp));
if((a0==NULL)||(a1==NULL)||(y0==NULL)||(y1==NULL))
{
printf("(p2c)memory alloc failed.\n");
return(0);
}
for(
i = 0;
i<k;
i++)                     /* ������ֳ�����*/
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
i = p2c1(y0, k, a0);                     /* �����ηֱ����*/
j = p2c1(y1, k, a1);
if(
i &&j
)                             /* ���������ɹ����������ֽ��ۺ�����*/
{
xn.
rmz = cos(-2 * PI / n);
xn.
imz = sin(-2 * PI / n);
x.
rmz = 1.0;
x.
imz = 0.0;

for(
i = 0;
i<k;
i++)
{
c_comp_product(&x, &a1[i], &t
);
c_comp_plus(&a0[i], &t, &a[i]
);        /* һ��һ��������˺���ֵ���ۺ�*/
c_comp_sub(&a0[i], &t, &a[i + k]
);
c_comp_product(&xn, &x, &x
);        /* x��xn��ˣ��������x�У���k���ۺ�ʱ��x����xn^k*/
}
}
free(y0);
free(y1);
free(a0);
free(a1);
return(1);
}
