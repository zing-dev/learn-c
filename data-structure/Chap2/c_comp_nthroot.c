/*======================================================
//��������c_comp_nthroot.c
//����������������n�η���
//���������a����֪������
//          n��n�η�����
//          c���������Ľṹ�壬��һ�����飬��n����
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define PI 3.1415926

/*struct c_comp{
    double rmz;
    double imz;
}c_comp;*/

int c_comp_nthroot(a, c, n)

struct c_comp *a, *c;
int n;
{
int i;
double R, theta;

if(a == NULL || c == NULL)
{
printf("(c_comp_nthroot)The c_comp pointer is NULL!\n");
return(0);
}

theta = atan2(a->imz, a->rmz);
R = sqrt(a->rmz * a->rmz + a->imz * a->imz);

R = pow(R, 1.0 / n);

for(
i = 0;
i<n;
i++)
{
c[i].
rmz = R * cos((theta + 2 * i * PI) / n);
c[i].
imz = R * sin((theta + 2 * i * PI) / n);
}
return(1);
}
