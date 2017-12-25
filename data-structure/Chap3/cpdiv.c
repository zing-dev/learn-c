/*=============================================================
// �� �� ����cpdiv(a,n,b,m,q,r)
// �������������ϵ����ʾ�ĸ�ϵ���Ķ���ʽA��B���
       �̶���ʽϵ������q���ʽϵ������r��
// ���������a������ʽAϵ������n��ϵ��������
       b������ʽBϵ������m��ϵ��������
       q���̶���ʽQϵ������k��ϵ��������k=max(n-m+1,0)
       r����ʽRϵ������l��ϵ����������Ҫl=n
// �� �� ֵ���������֡�����ɹ��򷵻�1�����򷵻�0
//==============================================================*/
#include"stdio.h"
#include"c_comp.c"

int cpdiv(a, n, b, m, q, k, r, l)
struct c_comp *a, *b, *q, *r;
int n, m, k, l;
{
int i, j, kk, jj;
struct c_comp t1, t2;
double tmp;
if((a==NULL)||(b==NULL)||(q==NULL)||(r==NULL))  /* ���ָ���Ƿ�Ϊ��*/
{
printf("(cpdiv)NULL pointer found.\n");
return(0);
}
if(l!=n)
{
printf("(cpdiv)please set the length of r to n.\n");
return(0);
}
for(
i = 0;
i<n;
i++)                      /* �Ƚ�a����r�У�����ǿ�ʼ����ǰ����ʽ*/
{
r[i].
rmz = a[i].rmz;
r[i].
imz = a[i].imz;
}
for(
i = 0;
i<k;
i++)                  /* ��ʱ����Ϊ0*/
{
q[i].
rmz = 0;
q[i].
imz = 0;
}
/* �ж϶���ʽB��ߴ���ϵ���Ƿ�Ϊ0*/
tmp = b[m - 1].rmz * b[m - 1].rmz + b[m - 1].imz * b[m - 1].imz;
if(tmp+1.0==1.0)
{
printf("(cpdiv)Cannot divide zero");
return(0);
}
b[m-1].
imz = -b[m - 1].imz;              /* ��ȡb[m-1]�Ĺ������������ת���ɳ˷�*/
for(
i = 0;
i<k;
i++)
{
kk = k - i - 1;
jj = n - i - 1;
c_comp_product(&r[jj], &b[m - 1], &t1
);          /* �����ǰ����*/
q[kk].
rmz = t1.rmz / tmp;
q[kk].
imz = t1.imz / tmp;
r[jj].
rmz = 0.0;                      /* ����ʽ�м�ȥ��ǰ���������ʽB�Ļ�*/
r[jj].
imz = 0.0;
for(
j = 0;
j<m-1; j++)
{
c_comp_product(&q[kk], &b[j], &t2
);
c_comp_sub(&r[j + kk], &t2, &r[j + kk]
);
}
}
b[m-1].
imz = -b[m - 1].imz;              /* �ָ�b[m-1]*/
return(1);
}

