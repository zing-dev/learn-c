/*======================================================
//��������randgsabs
//��������������L��N~(a,b)�ֲ��������
//���������L(���и���) a(��̬�ֲ��ľ�ֵ) b(��̬�ֲ��ķ���)��G(ָ�������������ָ��)
//����ֵ��1:���ɳɹ���0������ʧ��
=========================================================*/
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define PI 3.14159

double randgsabs(L, a, b, G)

int L;
double a, b;
double *G;
{
int i;
double U1, U2;
srand((
unsigned)time(0));/*��ϵͳʱ��������*/
for(
i = 0;
i<L;
i = i + 2
)
{
U1 = rand() / (double) RAND_MAX;/*����(0,1)�����U1*/
U2 = rand() / (double) RAND_MAX;/*����(0,1)�����U2*/
G[i]=sqrt(-2*
log(U1)
)*sin(2*PI*U2);/*���ɱ�׼��̬�ֲ������G1*/
G[i]=
sqrt(b)
*G[i]+
a;/*���ɷ���N~(a,b)�������G1*/
G[i+1]=sqrt(-2*
log(U1)
)*cos(2*PI*U2);/*���ɱ�׼��̬�ֲ������G2*/
G[i+1]=
sqrt(b)
*G[i+1]+
a;/*���ɷ���N~(a,b)�������G2*/
}
return(1);
}

