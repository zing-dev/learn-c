/*======================================================
//��������gillvh
//�����������䲽�������㷨��΢�ַ�����ĳ�ֵ����
//���������*y�� ָ������ֵ�Լ���������ֵ��ָ��n*(m+1)��
//          n���������������f��Ŀ�꺯���ļ��㣩
//          h����������m����������a��������㣩��eps�����ȣ�
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int gillvh(y, n, f, h, m, a, eps)

double *y, (*f)(), h, a, eps;
int n, m;
{
double x, *y1, *y2, *ytemp1, *ytemp2, dis, ht = h;
int k = 0, i, m1, m2;

int gillinvh();                              /* ��Ҫʹ�ö����������㷨���Ӻ���*/
y1 = (double *) malloc(sizeof(double) * n);        /* ��̬����*/
y2 = (double *) malloc(sizeof(double) * n);
if(y1==NULL||y2==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
do                                          /* ��k����ѭ�����ֱ����xk���ĺ���ֵ*/
{
x = a + k * h;
do{                                     /* ��ÿ��xk�������в����Ķ�̬ѡ��*/
m1 = (int) (h / ht);                     /* htΪ����*/
ytemp1 = (double *) malloc(sizeof(double) * n * (m1 + 1));
if(ytemp1==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
for(
i = n;
i< n
*(m1+1);i++)
ytemp1[i]=0.0;                  /* ��ʼ��*/
for(
i = 0;
i<n;
i++)
ytemp1[i]=y[
k *n
+i];
gillinvh(ytemp1, n, f, ht, m1, x
);       /* ���ö�������ʽ*/
for(
i = 0;
i<n;
i++)
y1[i]=ytemp1[
m1 *n
+i];
free(ytemp1);
m2 = 2 * m1;                            /* ht/2Ϊ����*/
ytemp2 = (double *) malloc(sizeof(double) * n * (m2 + 1));
if(ytemp2==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
for(
i = n;
i< n
*(m2+1);i++)
ytemp2[i]=0.0;
for(
i = 0;
i<n;
i++)
ytemp2[i]=y[
k *n
+i];
gillinvh(ytemp2, n, f, ht
/2,m2,x);
for(
i = 0;
i<n;
i++)
y2[i]=ytemp2[
m2 *n
+i];
free(ytemp2);
ht = ht / 2;                          /* ��һ��ѭ���Ĳ���*/
dis = 0.0;                          /* max����*/
for(
i = 0;
i<n;
i++)
if(
dis< fabs(y1[i] - y2[i])
)     /* ����˴��ĺ���ֵ*/
dis = fabs(y1[i] - y2[i]);
}
while(dis>=eps);                      /* �������Ƿ����㾫��*/
for(
i = 0;
i<n;
i++)
y[(k+1)*n+i]=y2[i];               /* �����¼*/
k++;                                  /* ��һ��xk*/
}
while(k<m);                               /* m��xk��ѭ��*/
free(y1);
free(y2);
return (1);
}

int gillinvh(y, n, f, h, m, a)
double *y, (*f)(), h, a;
int n, m;
{
double *k1, *k2, *k3, *k4, *ytemp, x, s2;
int k = 0, i;
s2 = sqrt(2) / 2;
k1 = (double *) malloc(sizeof(double) * n);    /* ΢�ַ���б��*/
k2 = (double *) malloc(sizeof(double) * n);
k3 = (double *) malloc(sizeof(double) * n);
k4 = (double *) malloc(sizeof(double) * n);
ytemp = (double *) malloc(sizeof(double) * n);

if(k1==NULL||k2==NULL||k3==NULL||k4==NULL||ytemp==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
do
{
x = a + k * h;
f(&y[k * n], k1, x
);                    /* k1*/
for(
i = 0;
i<n;
i++)
ytemp[i]=y[
k *n
+i]+
h *k1[i]
/2;
f(ytemp, k2, x
+h/2);                  /* k2*/
for(
i = 0;
i<n;
i++)
ytemp[i]=ytemp[i]+(s2-1)*
h *k1[i]
+(1-s2)*
h *k2[i];
f(ytemp, k3, x
+h/2);                  /* k3*/
for(
i = 0;
i<n;
i++)
ytemp[i]=y[
k *n
+i]-
s2 *h
*k2[i]+(1+s2)*
h *k3[i];
f(ytemp, k4, x
+h);                    /* k4*/

for(
i = 0;
i<n;
i++)                    /* ����˴��ĺ���ֵ*/
y[(k+1)*n+i]=y[
k *n
+i]+h/6*(k1[i]+(2-2*s2)*k2[i]+(2+2*s2)*k3[i]+k4[i]);
k++;
}
while(k<m);
free(k1);
free(k2);
free(k3);
free(k4);
free(ytemp);
return (1);
} 
