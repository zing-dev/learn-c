/*======================================================
// ��������c_gsjd
// �����������ø�˹��ȥ�������Է�����
// ���������a ��ϵ������b ��������x���صĽ�����
//           n δ֪��������eps ����Ҫ��С��eps��ֵ����Ϊ��0��
// ����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "c_comp.c"

int c_gsjd(a, b, x, n, eps)
struct c_comp *a, *b, *x;
int n;
double eps;
{
int i, j, k, l, v, exis, *exjs;
struct c_comp c_tmp;
double tmp, d;
if((a==NULL)||(b==NULL)||(x==NULL))             /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer exis NULL\n");
return(0);
}
exjs = malloc(n * sizeof(int));          /* Ϊ�н�����¼����ռ䲢����Ƿ�ɹ�*/
if(exjs == NULL)
{
printf("Memory alloc failed\n");
return(0);
}
for(
k = 0;
k<n;
k++)
{
d = 0.0;
for(
i = k;
i<n;
i++)                              /* ��ѭ������ѡȡ��Ԫ*/
for(
j = k;
j<n;
j++)
{
l = i * n + j;
tmp = a[l].rmz * a[l].rmz + a[l].imz * a[l].imz;  /* ��Ԫ�ص�ģ*/
if(tmp>d)
{
d = tmp;
exis = i;
exjs[k] =
j;
}
}
if(d<eps)                                     /* �ж���Ԫ�Ƿ��С*/
{
free(exjs);
printf("failed.\n");
return(0);                                    /* ����Ԫ��С���˳�����*/
}
if(exis!=k)                                       /* �ж��Ƿ���Ҫ�н���*/
{
for (
j = 0;
j<n;
j++)                           /* �����н���*/
{
l = k * n + j;
v = exis * n + j;
tmp = a[l].rmz;
a[l].
rmz = a[v].rmz;
a[v].
rmz = tmp;
tmp = a[l].imz;
a[l].
imz = a[v].imz;
a[v].
imz = tmp;
}
tmp = b[k].rmz;                              /* ��������ҲҪ�����н���*/
b[k].
rmz = b[exis].rmz;
b[exis].
rmz = tmp;
tmp = b[k].imz;
b[k].
imz = b[exis].imz;
b[exis].
imz = tmp;
}
if(exjs[k]!=k)                                   /* �ж��Ƿ���Ҫ�н���*/
for(
i = 0;
i<n;
i++)                           /* �����н���*/
{
l = i * n + k;
v = i * n + exjs[k];
tmp = a[l].rmz;
a[l].
rmz = a[v].rmz;
a[v].
rmz = tmp;
tmp = a[l].imz;
a[l].
imz = a[v].imz;
a[v].
imz = tmp;
}
l = k * n + k;                               /* ȡ�����������ת��Ϊ�˷�*/
a[l].
rmz = a[l].rmz / d;
a[l].
imz = -a[l].imz / d;
for(
j = k + 1;
j<n;
j++)           /* ��һ������ĵڶ�������Ҫʹ�ø����ĳ˷�*/
{
v = k * n + j;
c_comp_product(&a[v], &a[l], &a[v]
);
}
c_comp_product(&b[k], &a[l], &b[k]
);            /* ���������Ĺ�һ������*/

for(
i = 0;
i<n;
i++)                          /* ��Ԫ����*/
{
if(i!=k){
for(
j = k + 1;
j<n;
j++)
{
c_comp_product(&a[i * n + k], &a[k * n + j], &c_tmp
);
a[
i *n
+j].
rmz = a[i * n + j].rmz - c_tmp.rmz;
a[
i *n
+j].
imz = a[i * n + j].imz - c_tmp.imz;
}
c_comp_product(&a[i * n + k], &b[k], &c_tmp
);
b[i].
rmz = b[i].rmz - c_tmp.rmz;         /* ��������ҲҪ������Ԫ����*/
b[i].
imz = b[i].imz - c_tmp.imz;
}
}
}
for(
i = 0;
i<n;
i++)                          /* ���ڵ�b���ǽ�����*/
{
x[i].
rmz = b[i].rmz;
x[i].
imz = b[i].imz;
}
for(
k = n - 1;
k>=0; k--)                      /* �����н�������ʷ���н���ָ�*/
{
if(exjs[k]!=k)                             /* �ж��Ƿ���Ҫ�ָ�*/
{
tmp = x[k].rmz;                        /* �ָ����˳��*/
x[k].
rmz = x[exjs[k]].rmz;
x[exjs[k]].
rmz = tmp;
tmp = x[k].imz;
x[k].
imz = x[exjs[k]].imz;
x[exjs[k]].
imz = tmp;
}
}
free(exjs);                                  /* �ͷŷ���Ŀռ�*/
return(1);                                 /* ���ɹ�������1*/
}
