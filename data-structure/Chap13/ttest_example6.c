#include "stdio.h"
#include "stdlib.h"
#include "ttest.c"
#include "tutest.c"

#define pi 3.1415926

void main() {
    int j, na, nb, nc, rtab, rtbc, rtac;
    double *a, *b, *c;
    double x, meana, meanb, meanc, vara, varb, varc, alpha;
    na = 50;  /*����100�������*/
    nb = 70;
    nc = 60;
    alpha = 0.05;

    a = (double *) malloc(sizeof(double) * na);
    b = (double *) malloc(sizeof(double) * nb);
    c = (double *) malloc(sizeof(double) * nc);
    if (a == NULL || b == NULL || c == NULL) {
        printf("memory alloc failed.\n");
        exit(0);
    }

    for (j = 0; j < na; j++)                //���������һ
    {
        x = pi * j / na;
        a[j] = sin(x);
    }
    for (j = 0; j < nb; j++)              //���������
    {
        x = pi * j / nb;
        b[j] = cos(x);
    }
    for (j = 0; j < nc; j++)              //���������
    {
        x = pi * j / nc;
        c[j] = sin(x);
    }

    for (j = 0; j < na; j++)
        meana += a[j];
    meana = meana / na;                            //��������һ��ֵ
    for (j = 0; j < nb; j++)
        meanb += b[j];
    meanb = meanb / nb;                            //������������ֵ
    for (j = 0; j < nc; j++)
        meanc += c[j];
    meanc = meanc / nc;                            //������������ֵ
    for (j = 0; j < na; j++)
        vara += (a[j] - meana) * (a[j] - meana);
    vara = vara / (na - 1);                        //����һ�ķ���
    for (j = 0; j < nb; j++)
        varb += (b[j] - meanb) * (b[j] - meanb);
    varb = varb / (nb - 1);                        //�������ķ���
    for (j = 0; j < nc; j++)
        varc += (c[j] - meanc) * (c[j] - meanc);
    varc = varc / (nc - 1);                        //�������ķ���

    if (vara == varb)        //������ͬʱ����ttest
        rtab = ttest(a, na, b, nb, alpha);
    else
        rtab = tutest(a, na, b, nb, alpha);//���̲�ͬʱ����tutest

    if (rtab)
        printf("a��b�������Բ���\n");
    else
        printf("a��bû�������Բ���\n");

    if (varc == varb)
        rtbc = ttest(c, nc, b, nb, alpha);
    else
        rtbc = tutest(c, nc, b, nb, alpha);

    if (rtbc)
        printf("b��c�������Բ���\n");
    else
        printf("b��cû�������Բ���\n");
    if (vara == varc)
        rtac = ttest(a, na, c, nc, alpha);
    else
        rtac = tutest(a, na, c, nc, alpha);

    if (rtac)
        printf("a��c�������Բ���\n");
    else
        printf("a��cû�������Բ���\n");

}
