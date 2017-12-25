/*=============================================================
//��������randuab
//��������������һ��[a,b]����ľ��ȷֲ������������
//���������a ��b(���䷶Χ)
//����ֵ��һ��[a,b]�����ڵľ��ȷֲ��������
=========================================================*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

double randuab(a, b)

int a, b;
{
double u_ran;
int u_ran
srand((
unsigned)time(0));            /* ��ϵͳʱ��������*/
u_ran = rand() / (double) RAND_MAX;       /* ����(0,1)�����*/
uab_ran = (int) ((b - a + 1) * u_ran) + a;
return(uab_ran);
}

