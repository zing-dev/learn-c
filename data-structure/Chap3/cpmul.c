/*=============================================================
// �� �� ����cpmul(a,n,b,m,c)
// �������������ϵ����ʾ�ĸ�ϵ���Ķ���ʽA��B��ˣ����ϵ������c��
// ���������a������ʽAϵ������n��ϵ��������
	     b������ʽBϵ������m��ϵ��������
	     c�����صĶ���ʽC��ϵ����
// �� �� ֵ���������֡�����ɹ��򷵻�1�����򷵻�0
//==============================================================*/

#include"stdio.h"
#include"math.h"
#include"c_comp.c"    /*��ϵ������ʽ�ĳ˷�������Ҫ����ϵ���͵��ʾ�໥ת������������*/
#include"p2c.c"
#include"c2p.c"

int cpmul(a, n, b, m, c)
struct c_comp *a, *b, *c;
int n, m;
{
int i, k, nn;
struct c_comp *aa, *bb, *cc, *ya, *yb, *yc;

if((a==NULL) || (b==NULL) || (c==NULL))   /* ����Ƿ���ָ��Ϊ��*/
{
printf("(cpmul)NULL pointer found.\n");
return(0);
}

k = log(n + m - 1 - 0.5) / log(2.0) + 1;    /* ����С��k��������2^k ��С�ڶ���ʽC�Ľ���*/
nn = 1;                /* ���2^k*/
for(
i = 0;
i<k;
i++)
nn = nn << 1;
/* Ϊ��չ��Ķ���ʽ�����㹻�Ŀռ�*/
aa = (struct c_comp *) malloc(nn * sizeof(struct c_comp));
bb = (struct c_comp *) malloc(nn * sizeof(struct c_comp));
cc = (struct c_comp *) malloc(nn * sizeof(struct c_comp));
ya = (struct c_comp *) malloc(nn * sizeof(struct c_comp));
yb = (struct c_comp *) malloc(nn * sizeof(struct c_comp));
yc = (struct c_comp *) malloc(nn * sizeof(struct c_comp));

if(!(
aa &&bb
&&
cc &&ya
&&
yb &&yc
))   /* ����Ƿ���ָ��Ϊ��*/
{
printf("(cpmul)memory alloc failed.\n");
return(0);
}
for(
i = 0;
i<n;
i++)             /*��A,B��������ʽ�����2^k�׵ģ���ת����aa��bb��*/
{
aa[i].
rmz = a[i].rmz;
aa[i].
imz = a[i].imz;
}
for(
i = n;
i<nn;
i++)
{
aa[i].
rmz = 0;
aa[i].
imz = 0;
}
for(
i = 0;
i<m;
i++)
{
bb[i].
rmz = b[i].rmz;
bb[i].
imz = b[i].imz;
}
for(
i = m;
i<nn;
i++)
{
bb[i].
rmz = 0;
bb[i].
imz = 0;
}

i = c2p(aa, nn, ya);             /*�����չ�����ʽA�ĵ��ʾ��ʽ*/
k = c2p(bb, nn, yb);             /*�����չ�����ʽB�ĵ��ʾ��ʽ*/

if(
i &&k
)                 /* �����ʾ���ɹ����������㡣���򷵻�0*/
{

for(
i = 0;
i<nn;
i++)             /* �����ڸ����ϵĳ˻�*/
c_comp_product(&ya[i], &yb[i], &yc[i]
);
k = p2c(yc, nn, cc);             /*�������ʽC��ϵ��*/
if(k)                 /*�޳�����ĸ߽������p2c����ʧ�ܣ��򷵻�0*/
{
for(
i = 0;
i<m+n-1; i++)
{
c[i].
rmz = cc[i].rmz;
c[i].
imz = cc[i].imz;
}
return(1);
}
else
return(0);
}
else
return(0);
}
