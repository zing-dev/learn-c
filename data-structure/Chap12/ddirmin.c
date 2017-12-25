/*======================================================
// ��������ddirmin
// ������������������һά����
// ���������x[n] ���������ĳ�����
//           p[n] �����ķ���
//           xmin[n] �����ҵ������ŵ�
//           n ��ʼ�������һ���˵�
//           f ��Ԫ����ָ��
//           eps �����޶�
//           itmax ����������
// ����ֵ��  �����ļ�Сֵ
=========================================================*/
#include "stdlib.h"
#include "dbrent.c"
#include "mnbrak.c"

int _ndir_;
double *_pdir_, *_xdir_, *_xtdir_, *_dxtdir_;             /* ��Ҫȫ�ֱ���*/
double (*_myfc_)();

void (*_mydfc_)();                           /* ��Ҫȫ�ֱ���*/

double ddirmin(x, p, xmin, n, f, df, eps, itmax)
double *x, *xmin, *p, eps, (*f)(), (*df)();
int n, itmax;
{
int i;

double fdim(), dfdim(), ax, bx, cx, fopt, xopt;

_ndir_ = n;
_pdir_ = (double *) malloc(_ndir_ * sizeof(double));
_xdir_ = (double *) malloc(_ndir_ * sizeof(double));
_xtdir_ = (double *) malloc(_ndir_ * sizeof(double));
_dxtdir_ = (double *) malloc(_ndir_ * sizeof(double));
_myfc_ = f;                                            /* ȫ�ֱ���ָ����*/
_mydfc_ = df;

for(
i = 0;
i<n;
i++)
{
_pdir_[i] = p[i];
_xdir_[i] = x[i];
}
ax = 0.0;                                             /* ��ʼ���뷶Χ*/
bx = 0.5;
mnbrak(&ax, &bx, &cx, fdim
);                          /* ��һ����Сֵ����*/
fopt = dbrent(ax, bx, cx, fdim, dfdim, &xopt, eps, itmax);     /* ��brent�㷨�Ҽ�Сֵ*/
for(
i = 0;
i<n;
i++)                                    /* �ҵ������ŵ�x*/
{
p[i] =
xopt *p[i];
xmin[i] = x[i]+p[i];
}
free(_pdir_);
free(_xdir_);
free(_xtdir_);
free(_dxtdir_);
return(fopt);
}

double fdim(t)                                     /* ��f������������н�tʱ��ֵ*/
double t;
{
int i;
double y;
for(
i = 0;
i<_ndir_;
i++)
_xtdir_[i] = _xdir_[i] +
t *_pdir_[i];
y = _myfc_(_xtdir_, _ndir_);
return(y);
}

double dfdim(t)                                     /* ��f����������н���t���ĵ���ֵ*/
double t;
{
int i;
double df;
for(
i = 0;
i<_ndir_;
i++)
_xtdir_[i] = _xdir_[i] +
t *_pdir_[i];
_mydfc_(_xtdir_, _dxtdir_, _ndir_
);
df = 0.0;
for(
i = 0;
i<_ndir_;
i++)
df = df + _dxtdir_[i] * _pdir_[i];
return(df);
}