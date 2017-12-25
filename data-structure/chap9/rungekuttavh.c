/*======================================================
//��������rungekuttavh
//�����������䲽������-�����㷨��΢�ַ�����ĳ�ֵ����
//���������*y�� ָ������ֵ�Լ���������ֵ��ָ��n*(m+1)��
//          n���������������f��Ŀ�꺯���ļ��㣩
//          h����������m����������a��������㣩��eps�����ȣ�
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//#include"rungekuttainvh.c"

int rungekuttavh(y, n, f, h, m, a, eps)

double *y, (*f)(), h, a, eps;
int n, m;
{
double x, *y1, *y2, *ytemp1, *ytemp2, dis, ht = h;
int k = 0, i, m1, m2;

y1 = (double *) malloc(sizeof(double) * n);      /* ��̬����*/
y2 = (double *) malloc(sizeof(double) * n);
if(y1==NULL||y2==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
do                                         /* ��k����ѭ�����ֱ����xk���ĺ���ֵ*/
{
x = a + k * h;
do{                                    /* ��ÿ��xk�������в����Ķ�̬ѡ��*/
m1 = (int) (h / ht);                    /* htΪ����*/
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
ytemp1[i]=0.0;                      /* ��ʼ��*/
for(
i = 0;
i<n;
i++)
ytemp1[i]=y[
k *n
+i];
rungekuttainvh(ytemp1, n, f, ht, m1, x
);     /* ���ö�������ʽ*/
for(
i = 0;
i<n;
i++)
y1[i]=ytemp1[
m1 *n
+i];

free(ytemp1);

m2 = 2 * m1;                                 /* ht/2Ϊ����*/
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
rungekuttainvh(ytemp2, n, f, ht
/2,m2,x);
for(
i = 0;
i<n;
i++)
y2[i]=ytemp2[
m2 *n
+i];
free(ytemp2);

ht = ht / 2;                                 /* ��һ��ѭ���Ĳ���*/

dis = 0.0;                                 /* max����*/
for(
i = 0;
i<n;
i++)
if(
dis< fabs(y1[i] - y2[i])
)            /* ����˴��ĺ���ֵ*/
dis = fabs(y1[i] - y2[i]);
}
while(dis>=eps);                             /* �������Ƿ����㾫��*/

for(
i = 0;
i<n;
i++)
y[(k+1)*n+i]=y2[i];                      /* �����¼*/
k++;                                         /* ��һ��xk*/
}
while(k<m);                                      /* m��xk��ѭ��*/
free(y1);
free(y2);
return (1);
}

 
