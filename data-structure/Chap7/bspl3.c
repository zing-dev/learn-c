#include "stdio.h"
#include "math.h"

/*======================================================
// ��������bspl3
// ����������������߽���������������������ֵ
// ���������x ָ����n���������ݵ������ָ��
//           y ָ����n�����ĺ���ֵ�������ָ��
//           n ��������������Ҫ��n����Ϊ3
//           t ָ����m����ֵ������ݵ������ָ��
//           m ��ֵ�����
//           z ָ���ŷ��ص�m����ֵ�㴦�ĺ�������ֵ�������ָ��
//           z1 ָ���ŷ��ص�m����ֵ�㴦�ĺ���һ�׵����������ָ��
//           z2 ָ���ŷ��ص�m����ֵ�㴦�ĺ������׵����������ָ��
// ����ֵ��  �ɹ��򷵻����� 1��ʧ���򷵻� 0
=========================================================*/
int bspl3(x, y, n, t, m, z, z1, z2)

double *x, *y;
double *t, *z, *z1, *z2;
int m, n;
{
int i, j, k;
double y0, y1, *a, *b, *c, *p, *q, alpha, beta, *dy; /* ����dy���ñ���*/
double h1, h2, h3;                         /* ����z z1 z2ʱ���õı���*/
double t1, t2, t3, t4;                         /* ����z z1 z2ʱ���õ��ĸ�ϵ��*/
double tmp;
if(!(
x &&y
&&
t &&z
&&
z1 &&z2
))         /* �������ָ���Ƿ�Ϊ��*/
{
printf("Pointer is Null\n");
return(0);
}
if(n<3)                                     /* �ṩ�������3�Ͳ����в�ֵ��*/
{
printf("nodes less than 3");
return(0);
}
dy = (double *) malloc(n * sizeof(double));      /* ����ռ䲢����Ƿ�ɹ�*/
a = (double *) malloc(n * sizeof(double));
b = (double *) malloc(n * sizeof(double));
c = (double *) malloc(n * sizeof(double));
p = (double *) malloc(n * sizeof(double));
q = (double *) malloc(n * sizeof(double));
if(!(
dy &&a
&&
b &&c
&&
p &&q
))
{
free(dy);
free(a);
free(b);
free(c);
free(p);
free(q);
printf("Memory alloc failed\n");
return(0);
}
a[0] = 0.0;                                         /* a���鸳��ֵ*/
b[0] = 1.0;                                         /* b���鸳��ֵ*/
c[0] = 0.0;                                         /* c���鸳��ֵ*/
h1 = x[n - 1] - x[n - 2];
y0 = y[n - 1] - y[n - 2];
for(
i = 1;
i<n-1; i++)                                 /* ���Ƽ���a,b,c*/
{
h2 = h1;
y1 = y0;
h1 = x[i] - x[i - 1];
y0 = y[i] - y[i - 1];
alpha = h2 / (h2 + h1);
beta = (1.0 - alpha) * y1 / h2;
beta = 3.0 * (beta + alpha * y0 / h1);
tmp = 1.0 / (2.0 + (1.0 - alpha) * a[i - 1]);
a[i] = -
alpha *tmp;
b[i] = (alpha-1.0)*b[i-1]*
tmp;
c[i] = (beta+(alpha-1.0)*c[i-1])*
tmp;
}
h2 = x[n - 1] - x[n - 2];                             /* �������һ��alpha��beta*/
y1 = y[n - 1] - y[n - 2];
alpha = h1 / (h1 + h2);
beta = (1.0 - alpha) * y0 / h1;
beta = 3.0 * (beta + alpha * y1 / h2);
p[n-2] = 1.0;                                   /* ����p,qֵ*/
q[n-2] = 0.0;
for(
i = n - 2;
i>0; i--)
{
p[i-1] = a[i]*p[i]+b[i];
q[i-1] = a[i]*q[i]+c[i];
}
dy[n-2] = (beta-
alpha *q[0]
+(alpha-1.0)*q[n-3]);  /* dy����ֵ*/
dy[n-2] = dy[n-2]/(2.0+
alpha *p[0]
+(1.0-alpha)*p[n-3]);
for(
i = 0;
i<n-2; i++)                          /* ���Ƽ����㴦��һ�׵���dy*/
dy[i] = p[i]*dy[n-2]+q[i];
dy[n-1] = dy[0];
for(
k = 0;
k<m;
k++)
{
tmp = t[k];
j = 0;
while((x[j]<tmp)&&(j<n))                      /* Ѱ�Һ��ʵ�����*/
j++;
j = j - 1;
if(j<1)
j = 0;
if(j>(n-1))
j = n - 2;
h1 = x[j + 1] - x[j];                             /* h*/
h2 = h1 * h1;                                  /* h^2*/
h3 = h2 * h1;                                  /* h^3*/
t1 = 3.0 * y[j + 1] / h2 - 1.0 * dy[j + 1] / h1;           /* ����4��ϵ��*/
t2 = 2.0 * y[j + 1] / h3 - 1.0 * dy[j + 1] / h2;
t3 = 3.0 * y[j] / h2 + 1.0 * dy[j] / h1;
t4 = 2.0 * y[j] / h3 + 1.0 * dy[j] / h2;
z[k] = (t1-
t2 *(tmp
-x[j]))*(tmp-x[j])*(tmp-x[j]);    /* ���㺯������ֵ*/
z[k] = z[k] + (t3 -
t4 *(x[j + 1]
-tmp))*(x[j+1]-tmp)*(x[j+1]-tmp);
z1[k] = (2.0*t1-3.0*
t2 *(tmp
-x[j]))*(tmp-x[j]);      /* ����һ�׵���*/
z1[k] = z1[k] + (-2.0*t3 + 3.0*
t4 *(x[j + 1]
-tmp))*(x[j+1]-tmp);
z2[k] = 2.0*t1-6.0*
t2 *(tmp
-x[j]);                   /* ������׵���*/
z2[k] = z2[k] + 2.0*t3 - 6.0*
t4 *(x[j + 1]
-tmp);
}
free(dy);
free(a);
free(b);
free(c);
free(p);
free(q);
return(1);
}
