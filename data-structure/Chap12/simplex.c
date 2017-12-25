/*======================================================
// ��������simplex
// ���������� �����Թ滮����ĵ����η�
// ���������n   �����ά��
//           m1  ��һ��Լ�������ĸ���
//           m2  �ڶ���Լ�������ĸ���
//           m3  ��ʽԼ�������ĸ���
//           a[(m+2)*(n+1)] �����α�Ĵ�ſռ䣬ǰm+1�������������
//                          ��������ʱ�����ص����α�����ս��
//           ixr[n] �����α��һ�е�x���
//           ixc[m] �����α��һ�е�x���
//           eps  ����Ҫ��һ��Ϊ1.0e-6
// ����ֵ��  �����ɹ����򷵻�0���������޽⣬�򷵻�1�����޿��н⣬�򷵻�-1
=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define TINY 1.0e-7

int simplex(a, n, m1, m2, m3, ixr, ixc, eps)

int n, m1, m2, m3, *ixr, *ixc;
double *a, eps;
{
int i, j, k, m, mp, np, ip, jp, flag;
int lisx[101], lism2[101], nl1;

int cmax1(), cmax2(), pivot();

void mswap();

double tmp, cmax;

m = m1 + m2 + m3;
if(n > 100)
{
printf("n should less than 100\n");
return(-1);
}
mp = m + 2;
np = n + 1;                                    /* ������Ĺ�ģ*/
for(
i = 0;
i<=
m;
i++)
{
if(a[
i *np
] < 0.0)                        /* ��һ��Ҫ��ȫ���Ǹ�*/
{
printf("negative B%d found\n",i);
return(-1);
}
ixc[i] = n+
i;                                    /* ���ֱ������n+1~n+m*/
}
for(
k = 0;
k<=
n;
k++)                                      /* ���ֱ������1~n*/
{
lisx[k] =
k;
ixr[k] =
k;
}
nl1 = n;
if(m2+m3>0)                                               /* ��Ҫ�⸨������*/
{
for(
i = 0;
i<=
m2;
i++)
lism2[i] = 1;                                     /* m2���͵��ƶ���¼*/
for(
j = 0;
j<np;
j++)                                   /* ���㸨�����⣬�������*/
{
tmp = 0.0;
for(
i = m1 + 1;
i<=
m;
i++)
tmp = tmp + a[i * np + j];
a[(m+1)*np+j] = -
tmp;                             /* ��ͽ����������һ��*/
}
flag = 1;
while(flag == 1)
{
jp = cmax1(a, mp, np, m + 1, lisx, nl1, &cmax);            /* �����һ���е�ϵ�����ֵ*/
if(cmax <=
eps &&a[(m + 1) * np]
< -eps)
{                                     /* ϵ���������ģ����Ҵ�ʱ�ļ�СֵҲС��0*/
printf("no feasible solution.\n");             /* �޿��н�*/
return(-1);
}
else if(cmax <=
eps &&a[(m + 1) * np]
<=eps)
{                                    /* �Ѿ��ҵ�������������Ž⣬Ҫ��������z*/
for(
ip = m1 + m2 + 1;
ip<=
m;
ip++)
{
if(ixc[ip] == ip+n)                        /* �ҵ�һ������z*/
{                            /* �ڱ�����һ��ϵ������ֵ���ģ����л�Ԫ*/
jp = cmax2(a, mp, np, ip, lisx, nl1, &cmax);
if(
fabs(cmax)
> eps)
{
mswap(a, mp, np, ip, jp
);
for(
j = 1;
j<=
nl1;
j++)
if(lisx[j] == jp)
break;
nl1--;                           /* ��һ���Ժ��ٹ���*/
for(
k = j;
k<=
nl1;
k++)
lisx[k] = lisx[k+1];
i = ixr[jp];              /* �������ֱ��������ֱ�������*/
ixr[jp] = ixc[ip];
ixc[ip] =
i;
}
}
}
for(
i = 1;
i<=
m2;
i++)      /* ��m2�α���������ǰ�棬����z��ͬʱ����Ҫȡ����*/
{
if(lism2[i] == 1)
{
k = (i + m1) * np;
for(
j = 0;
j<np;
j++)                   /* ����ϵ��ȡ����*/
a[k+j] = -a[k+j];
a[k] = 0;
}
}
flag = 0;                                      /* ��ʼ�ڶ��׶�*/
}
else
{
ip = pivot(a, mp, np, m, n, jp);                        /* ѡ��Ԫ*/
if(ip==0)                                          /* �޿��н�*/
{
printf("no feasible solution.\n");
return(-1);
}
mswap(a, mp, np, ip, jp
);                 /* ������ip�к͵�jp�ж�Ӧ�ı���*/
if(ixc[ip] > n+m1+m2)                /* ������һ��z���Ҳ���m2�͵�����*/
{
for(
j = 1;
j<=
nl1;
j++)
if(lisx[j] == jp)
break;
nl1--;                           /* ��һ���Ժ��ٹ���*/
for(
k = j;
k<=
nl1;
k++)
lisx[k] = lisx[k+1];
}
else if(ixc[ip] > n+m1)                  /* ������һ��z��������m2�͵�����*/
{
i = ixc[ip] - n - m1;
if(lism2[i] == 1)          /* ��ʵ���ǽ�x(n+m1+i)��Ӧ���н�������jp��*/
{                                       /* Ҳ���������x�滻z*/
lism2[i] = 0;
a[(m+1)*np+jp]++;
for(
i = 0;
i<mp;
i++)
a[
i *np
+jp] = -a[
i *np
+jp];
}
}
i = ixr[jp];                             /* �������ֱ��������ֱ�������*/
ixr[jp] = ixc[ip];
ixc[ip] =
i;
}
}
}
while(1)
{
jp = cmax1(a, mp, np, 0, lisx, nl1, &cmax);        /* �������ֵ*/
if(cmax<eps)
return(0);                                 /* �Ѿ��ҵ����Ž�*/
ip = pivot(a, mp, np, m, n, jp);                    /* ѡ��Ԫ*/
if(ip ==0)
return(1);                                 /* û�����޽�*/
mswap(a, mp, np, ip, jp
);                          /* ����*/
i = ixr[jp];                             /* �������ֱ��������ֱ�������*/
ixr[jp] = ixc[ip];
ixc[ip] =
i;
}
}

int cmax1(a, mp, np, mm, ll, nll, cmax) /* ��������a�е�mm������ll�и����е����Ԫ��cmax*/
double *a, *cmax;                                 /* ���ش����Ԫ�ص��к�*/
int mp, np, mm, *ll, nll;                         /* mp,np�Ƕ�ά����a�Ĺ�ģ*/
{
int kp, k;
double tmp;
kp = ll[1];
*
cmax = a[mm * np + kp];
for(
k = 2;
k<=
nll;
k++)                         /* �Ƚ�*/
{
tmp = a[mm * np + ll[k]];
if(tmp > *cmax)
{
*
cmax = tmp;
kp = ll[k];
}
}
return(kp);
}

#include "math.h"                 /* ��������a�е�mm������ll�и����еľ���ֵ����Ԫ��cmax*/

int cmax2(a, mp, np, mm, ll, nll, cmax)
double *a, *cmax;                                 /* ���ش����Ԫ�ص��к�*/
int mp, np, mm, *ll, nll;                         /* mp,np�Ƕ�ά����a�Ĺ�ģ*/
{
int kp, k;
double tmp;
kp = ll[1];
*
cmax = fabs(a[mm * np + kp]);
for(
k = 2;
k<=
nll;
k++)                        /* �ȽϾ���ֵ*/
{
tmp = fabs(a[mm * np + ll[k]]);
if(tmp > *cmax)
{
*
cmax = tmp;
kp = ll[k];
}
}
*
cmax = a[mm * np + kp];
return(kp);
}

int pivot(a, mp, np, m, n, kp)                  /* ѡ��Ԫ�����ǵ����˻������*/
double *a;
int mp, np, m, n, kp;
{
int ip, i, k;
double p0, p1, p2, p3, tmp1, tmp2;
ip = 0;
for(
i = 1;
i<=
m;
i++)                         /* �����Ƿ��и�Ԫ��*/
if(a[
i *np
+kp] < -TINY)
break;
if(i>m)
return(ip);
p0 = -a[i * np] / a[i * np + kp];                   /* ��һ����Ԫ��*/
ip = i;
for(
i = ip + 1;
i<=
m;
i++)
{
if(a[
i *np
+kp] < -TINY)                  /* ��һ����Ԫ��*/
{
p1 = -a[i * np] / a[i * np + kp];
if(p1<p0)
{
ip = i;
p0 = p1;
}
else if(p1 == p0)                   /* �˻���*/
{
tmp1 = 1.0 / (a[ip * np + kp]);
tmp2 = 1.0 / (a[i * np + kp]);
for(
k = 1;
k<=
n;
k++)
{
p2 = -a[ip * np + k] * tmp1;
p3 = -a[i * np + k] * tmp2;
if(p2 != p3)
break;
}
if(p3<p2)                      /* ѡ���С��һ��*/
ip = i;
}
}
}
return(ip);
}

void mswap(a, mp, np, ip, kp)                        /* ��Ԫ��ipָ�����к�kpָ����*/
double *a;
int mp, np, ip, kp;
{
int i, k;
double tmp;
tmp = 1.0 / a[ip * np + kp];
for(
i = 0;
i<ip;
i++)                               /* �ȱ任��ip��֮�����*/
{
a[
i *np
+kp] = a[
i *np
+kp]*
tmp;
for(
k = 0;
k<kp;
k++)
a[
i *np
+k] = a[
i *np
+k]-a[
ip *np
+k]*a[
i *np
+kp];
for(
k = kp + 1;
k<np;
k++)
a[
i *np
+k] = a[
i *np
+k]-a[
ip *np
+k]*a[
i *np
+kp];
}
for(
i = ip + 1;
i<mp;
i++)
{
a[
i *np
+kp] = a[
i *np
+kp]*
tmp;
for(
k = 0;
k<kp;
k++)
a[
i *np
+k] = a[
i *np
+k]-a[
ip *np
+k]*a[
i *np
+kp];
for(
k = kp + 1;
k<np;
k++)
a[
i *np
+k] = a[
i *np
+k]-a[
ip *np
+k]*a[
i *np
+kp];
}
a[
ip *np
+kp] = a[
ip *np
+kp]*
tmp;                       /* �任��ip��*/
tmp = -tmp;
for(
k = 0;
k<kp;
k++)
a[
ip *np
+k] *=
tmp;
for(
k = kp + 1;
k<np;
k++)
a[
ip *np
+k] *=
tmp;
}