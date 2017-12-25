/*======================================================
//��������randuabs
//��������������[a,b]����ľ��ȷֲ��������������
//���������L(����������еĳ���)��a��b�����䷶Χ��,uab_ran(ָ��������������е�ָ��)
//����ֵ��1���ɹ����ɡ�0������ʧ��
=========================================================*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int randuabs(L, a, b, uab_ran)

int L, a, b;
int *uab_ran;
{
int i;
double *u_ran;
u_ran = (double *) malloc(L * sizeof(double));
if(u_ran==NULL)
{
printf("memory alloc failed.\n");
return(0);
}
srand((
unsigned)time(0));                     /* ��ϵͳʱ��������*/
for(
i = 0;
i<L;
i++)
{
u_ran[i]=

rand()

/(double)
RAND_MAX;         /* ����(0,1)�������L��*/
uab_ran[i]=(int)(u_ran[i]*(b-a+1))+
a;
}
return(1);
}

