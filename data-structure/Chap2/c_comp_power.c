/*======================================================
//��������c_comp_power.c
//���������������ĳ���
//���������a�������Ľṹ�壩
//          n��ָ����
//          c���������Ľṹ�壩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

/*struct c_comp{
    double rmz;
    double imz;
}c_comp;
*/
int c_comp_power(a, c, n)

struct c_comp *a, *c;
int n;
{
double R, theta;

if(a == NULL || c == NULL)
{
printf("(c_comp_power)The c_comp pointer is NULL!\n");
return(0);
}

theta = atan2(a->imz, a->rmz);
R = sqrt(a->rmz * a->rmz + a->imz * a->imz);

theta = n * theta;
R = pow(R, n);

c->
rmz = R * cos(theta);
c->
imz = R * sin(theta);
return(1);
}