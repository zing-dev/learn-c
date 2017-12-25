/*======================================================
//��������c_comp_sin.c
//��������������������
//���������a������Ľṹ�壩
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
int c_comp_sin(a, c)

struct c_comp *a, *c;
{
double tmp1, tmp2;

if(a == NULL || c == NULL)
{
printf("(c_comp_sin)The c_comp pointer is NULL!\n");
return(0);
}

tmp1 = exp(a->imz);
tmp2 = exp(-a->imz);
c->
rmz = sin(a->rmz) * (tmp1 + tmp2) / 2;
c->
imz = cos(a->rmz) * (tmp1 - tmp2) / 2;

return(1);
}