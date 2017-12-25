/*======================================================
//��������c_comp_divide.c
//���������������ĳ���
//���������a1��������a�Ľṹ�壩
//          a2������b�Ľṹ�壩
//          c���������Ľṹ�壩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int c_comp_divide(a1, a2, c)

struct c_comp *a1, *a2, *c;
{
double R2;
if(a1 == NULL || a2 == NULL || c == NULL)
{
printf("(c_comp_divide)The c_comp pointer is NULL!\n");
return(0);
}

R2 = (a2->rmz) * (a2->rmz) + (a2->imz) * (a2->imz);

c_comp_product(a1, a2, c
);
c->
rmz = c->rmz / R2;
c->
imz = c->imz / R2;

return(1);
}