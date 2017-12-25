/*======================================================
//��������randgsab
//��������������N~(a,b)�ֲ��������
//���������a(��̬�ֲ��ľ�ֵ) b(��̬�ֲ��ķ���)
//����ֵ����̬�ֲ��������
=========================================================*/
#include "time.h"
#include"stdlib.h"
#include"stdio.h"
#include"math.h"

#define PI 3.14159

double randgsab(a, b)

double a, b;
{
double U1, U2, G;
srand((
unsigned)time(0));/*��ϵͳʱ��������*/
U1 = rand() / (double) RAND_MAX;/*����(0,1)�����U1*/
U2 = rand() / (double) RAND_MAX;/*����(0,1)�����U2*/
G = sqrt(-2 * log(U1)) * sin(2 * PI * U2);/*���ɱ�׼��̬�ֲ������G*/
G = sqrt(b) * G + a;/*���ɷ���N~(a,b)�������G*/
return(G);
}

