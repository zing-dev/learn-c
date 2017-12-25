/*======================================================
//��������c_comp_product.c
//���������������ĳ˷�
//���������a1����һ������a�Ľṹ�壩
//          a2���ڶ�������b�Ľṹ�壩
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
int c_comp_product(a1, a2, c)

struct c_comp *a1, *a2, *c;
{
double p, q, s;
if(a1 == NULL || a2 == NULL || c == NULL)
{
printf("(c_comp_product)The c_comp pointer is NULL!\n");
return(0);
}
p = (a1->rmz) * (a2->rmz);
q = (a1->imz) * (a2->imz);
s = (a1->rmz + a1->imz) * (a2->rmz + a2->imz);
c->
rmz = p - q;
c->
imz = s - p - q;
return(1);
}