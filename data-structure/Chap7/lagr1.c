#include "stdio.h"
#include "math.h"
/*======================================================
// ��������lagr1
// ���������������������Բ�ֵ
// ���������x ָ����n���������ݵ������ָ��
//           y ָ����n�����ĺ���ֵ�������ָ��
//           n ��������
//           t ָ���Ĳ�ֵ��
// ����ֵ��  ��ָ����ֵ��ĺ�������ֵ
=========================================================*/
double lagr1(x,y,n,t)
double *x,*y,t;
int n;
{
  int i,j,k;
  double z;
  if((x==NULL)||(y==NULL))             /* �������ָ���Ƿ�Ϊ��*/
  {
    printf("Pointer is Null\n");
    return(0.0);
  }
  if(n<1)                              /* û���ṩ��㣬����0.0*/
    return(0.0);
  if(n==1)                             /* ֻ��һ����㣬���ش˺���ֵ*/
    return(y[0]);
  i = 0;
  while((x[i]<t)&&(i<n))               /* Ѱ�Һ��ʵ�����*/
    i++;
  i = i-1;
  if(i < 1)
    i = 0;
  if(i > (n-2))
    i = n-2;
  printf("lagr1: %d,%d\n",i,i+1);      /* ��ӡʹ�õ�����*/
  z = (y[i]*(t-x[i+1]) - y[i+1]*(t-x[i]))/(x[i] - x[i+1]); /* �������ֵ*/
  return(z);
}