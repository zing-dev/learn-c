#include "stdio.h"
#include "stdlib.h"
#include "ftest.c"

#define pi 3.1415926

void main() {
    int j, na, nb, nc, rtab, rtbc, rtac;
    double *a, *b, *c;
    double x, alpha;
    na = 50;       /* ����10�������*/
    nb = 70;
    nc = 60;
    alpha = 0.1;

    a = (double *) malloc(sizeof(double) * na);
    b = (double *) malloc(sizeof(double) * nb);
    c = (double *) malloc(sizeof(double) * nc);
    if (a == NULL || b == NULL || c == NULL) {
        printf("memory alloc failed.\n");
        exit(0);
    }
    for (j = 0; j < na; j++)                //���������a
    {
        x = pi * j / na;
        a[j] = sin(x);
    }
    for (j = 0; j < nb; j++)              //�������b
    {
        x = pi * j / nb;
        b[j] = cos(x);
    }
    for (j = 0; j < nc; j++)              //�������c
    {
        x = pi * j / nc;
        c[j] = sin(x);
    }
    rtab = ftest(a, na, b, nb, alpha);         /* ����a��b*/
    if (rtab)
        printf("a��b�������Բ���\n");
    else
        printf("a��bû�������Բ���\n");


    rtbc = ftest(c, nc, b, nb, alpha);         /* ����b��c*/
    if (rtbc)
        printf("b��c�������Բ���\n");
    else
        printf("b��cû�������Բ���\n");

    rtac = ftest(a, na, c, nc, alpha);        /* ����a��c*/
    if (rtac)
        printf("a��c�������Բ���\n");
    else
        printf("a��cû�������Բ���\n");

}
