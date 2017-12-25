/*======================================================
//��������c_comp_pow.c
//��������������ָ��
//���������a������Ľṹ�壩
//          c���������Ľṹ�壩
//����ֵ��0��ʧ�ܣ���1���ɹ���
=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "c_comp_product.c"

/*struct c_comp{
    double rmz;
    double imz;
}c_comp;
*/
int c_comp_exp(a, c)
struct c_comp *a, *c;
{
double R;

if(a == NULL || c == NULL)
{
printf("(c_comp_exp)The c_comp pointer is NULL!\n");
return(0);
}

R = exp(a->rmz);

c->
rmz = R * cos(a->imz);
c->
imz = R * sin(a->imz);

return(1);
}