/*======================================================
//��������mhdqr
//������������H����������ֵ
//���������a   ָ������H�����ָ��
			n   �������
			u   ���ص�����ֵ��ʵ��
			v   ���ص�����ֵ���鲿
			eps ����Ҫ�������ж�Ԫ���Ƿ�Ϊ0
			itmax ����������
//����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int mhdqr(a, n, u, v, eps, itmax)

double *a, *u, *v, eps;
int n, itmax;
{
int i, j, k, ii, jj, kk;
double x, y, p, q, r;                          /* ���ڽ������Ʊ任*/
double q00, q01, q02, q11, q12, q22;            /* ������Q*/
int is1, is2, n1;                            /* ���ڷֽ�����*/
double *a1;                                /* ���ڴ��С��ģ������*/
double b, c, s;                              /* ���ڼ���2�׾��������ֵ*/
if(itmax == 0)                            /* �Ѿ������ٵ���*/
{
printf("fail\n");
return(0);
}
if(n==1)                                   /* ������1��*/
{
u[0] = a[0];
v[0] = 0.0;
return(1);
}
if(n==2)                                  /* ������2��*/
{
b = (a[0] + a[3]);
c = a[0] * a[3] - a[1] * a[2];
s = b * b - 4.0 * c;
y = sqrt(fabs(s));
if (s > 0.0)                           /* ��������ֵ��ʵ��*/
{
if(b > 0.0)
u[0] = (b+y)/2.0;
else
u[0]=(b-y)/2.0;
v[0]=0.0;
u[1]=c/u[0]; v[1]=0.0;
}
else                                   /* ��������ֵ�Ǹ������*/
{
u[0] = b/2.0; v[0] = y/2.0;
u[1] = u[0]; v[1] = -v[0];
}
return(1);
}
is1 = 0;
is2 = 0;
while(is2<n-1)                           /* �ָ��С��ģ����*/
{
is2++;
j = is2 * n + is2;
if(
fabs(a[j - 1])
<
eps *(fabs(a[j - n - 1])
+
fabs(a[j])
)) /* Ѱ�ҴζԽ�����0Ԫ��*/
{
n1 = is2 - is1;
printf("Partion: is1=%d,is2=%d,size=%d\n",is1,is2,n1);
a1 = (double *) malloc(n1 * n1 * sizeof(double));
for(
i = 0;
i<n1;
i++)
for(
j = 0;
j<n1;
j++)
a1[
i *n1
+j] = a[(i+is1)*n+j+is1];
mhdqr(a1, n1, u
+is1,v+is1,eps,itmax);   /* �ݹ���ú������*/
free(a1);
is1 = is2;
}
}
if(is1>0 && is1<n)                           /* ���й��ָ�����һ�����δ���*/
{
n1 = n - is1;
printf("Partion: is1=%d,is2=%d,size=%d\n",is1,n,n1);
a1 = (double *) malloc(n1 * n1 * sizeof(double));
for(
i = 0;
i<n1;
i++)
for(
j = 0;
j<n1;
j++)
a1[
i *n1
+j] = a[(i+is1)*n+j+is1];
mhdqr(a1, n1, u
+is1,v+is1,eps,itmax);     /* �ݹ���ú���������һ�����*/
free(a1);
return(1);
}
else if(is1  == n)
return(1);
for (
k = 0;
k<n-1; k++)
{
if(k==0)                                 /* �����һ��Ӧ����λ�Ʋ���*/
{
x = a[(n - 2) * n + n - 2] + a[n * n - 1];
y = a[(n - 2) * n + n - 2] * a[n * n - 1] - a[(n - 2) * n + n - 1] * a[(n - 1) * n + n - 2];
p = a[0] * (a[0] - x) + a[1] * a[n] + y;
q = a[n] * (a[0] + a[n + 1] - x);
r = a[n] * a[2 * n + 1];
}
else                      /* ������е��������Ҫ������ָ�����H����*/
{
p = a[k * n + k - 1];
q = a[(k + 1) * n + k - 1];
if(k != n-2)
r = a[(k + 2) * n + k - 1];
else
r = 0.0;
}
if ((
fabs(p)
+
fabs(q)
+
fabs(r)
)!=0.0)    /* ����0����һ�оͲ���Ҫ����*/
{
if(p<0.0)                          /* ��Q*/
s = -sqrt(p * p + q * q + r * r);
else
s = sqrt(p * p + q * q + r * r);
if(k!=0)
a[
k *n
+k-1]=-
s;
q00 = -p / s;                     /* Q�ĸ�������Ԫ��*/
q01 = -q / s;
q02 = -r / s;
q11 = -q00 - q02 * r / (p + s);
q12 = q01 * r / (p + s);
q22 = -q00 - q01 * q / (p + s);
for(
j = k;
j<n;
j++)           /* Q���A�����ı�k,k+1,k+2��3���ϵ�n-k��Ԫ��*/
{
ii = k * n + j;
jj = (k + 1) * n + j;
kk = (k + 2) * n + j;
p = q00 * a[ii] + q01 * a[jj];
q = q01 * a[ii] + q11 * a[jj];
r = q02 * a[ii] + q12 * a[jj];
if (k!=n-2)                    /* ��kΪn-2ʱ��ֻ�ı�2��*/
{
p = p + q02 * a[kk];
q = q + q12 * a[kk];
r = r + q22 * a[kk];
a[kk] =
r;
}
a[ii] =
p;
a[jj] =
q;
}

j = k + 3;                         /* ����Q�ҳ�AӰ�����������Ҫ�Ǳ߽�����*/
if(j>=n-1)
j = n - 1;
for(
i = 0;
i<=
j;
i++)           /* Q�ҳ�A�����Ӱ��3�У���k,k+1,k+2��*/
{
ii = i * n + k;
jj = i * n + k + 1;
p = q00 * a[ii] + q01 * a[jj];
q = q01 * a[ii] + q11 * a[jj];
r = q02 * a[ii] + q12 * a[jj];
if(k!=n-2)               /* ��k+2Ϊnʱ����������һ���ˣ���ΪԽ����*/
{
kk = i * n + k + 2;
p = p + q02 * a[kk];
q = q + q12 * a[kk];
r = r + q22 * a[kk];
a[kk]=
r;
}
a[ii]=
p;
a[jj]=
q;
}
}
if(k > 0)                      /* ������Ԫ����0*/
{
a[(k+1)*n+k-1] = 0.0;
if(k != n-2)
a[(k+2)*n+k-1] = 0.0;
}
}
/*	for (j=2; j<=n-1; j++)                       ��֤����H����
		a[j*n+j-2]=0.0;
	for (j=3; j<=n-1; j++)                       
		a[j*n+j-3]=0.0;*/
i = mhdqr(a, n, u, v, eps, itmax - 1);    /* ���������Ʊ任���ٵݹ���ú������*/
return(i);
}

