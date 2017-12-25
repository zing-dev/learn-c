#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "kabg.c"

#define PI 3.1415926

void main() {
    int i;
    void rand_gauss_lot();
    double x[200], y[200], z[200];
    double a, b, c, h, t;
    a = 0.281;
    b = 0.0285;
    c = 0.0005;
    h = 0.02;
    rand_gauss_lot(200, 0.0, 0.25, y);                     /* ����200����˹�����*/
    for (i = 0; i < 200; i++) {
        t = (i + 1) * h;
        z[i] = -5.0 * t + 3.0;                             /* 200����ʵ�ź�*/
        x[i] = z[i] + y[i];                              /* 200�����������ź�*/
    }
    kabg(x, 200, y, h, a, b, c);                             /* �˲�����*/
    for (i = 180; i < 200; i++)                           /* ��ӡ���20������ֵ*/
    {
        t = (i + 1) * h;
        printf("t=%5.2f  x(t)=%5.2f  y(t)=%5.2f  z(t)=%5.2f\n",
               t, x[i], y[i], z[i]);
    }
}

static void rand_gauss_lot(L, a, b, G)                    /* ������˹������ĺ���*/
int L;
double a, b;
double *G;
{
int i;
double U1, U2;
srand((
unsigned)time(0));                 /* ��ϵͳʱ��������*/
for(
i = 0;
i<L;
i = i + 2
)
{
U1 = rand() / (double) RAND_MAX;           /* ����(0,1)�����U1*/
U2 = rand() / (double) RAND_MAX;           /* ����(0,1)�����U2*/
G[i]=sqrt(-2*
log(U1)
)*sin(2*PI*U2);   /* ���ɱ�׼��̬�ֲ������G1*/
G[i]=
sqrt(b)
*G[i]+
a;                  /* ���ɷ���N~(a,b)�������G1*/
G[i+1]=sqrt(-2*
log(U1)
)*cos(2*PI*U2); /* ���ɱ�׼��̬�ֲ������G2*/
G[i+1]=
sqrt(b)
*G[i+1]+
a;              /* ���ɷ���N~(a,b)�������G2*/
}
return;
}
