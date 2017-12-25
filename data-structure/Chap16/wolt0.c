#include "stdio.h"
#include "math.h"
#include "wolt.c"
#include "hadma.c"

void main() {
    int i, n = 8;
    double a[8], b[8], y[8];
    for (i = 0; i < n; i++)                                 /* ����a��b*/
    {
        a[i] = i + 1;
        b[i] = 2 * i;
    }
    printf(" a sequence\n");
    for (i = 0; i < n; i++)
        printf("%5.4f ", a[i]);
    printf("\n b sequence\n");
    for (i = 0; i < n; i++)
        printf("%5.4f ", b[i]);
    i = wolt(a, n, y);                                     /*��a��wolt�任*/
    if (i) {
        printf("\n\nwolt of a:\n");
        for (i = 0; i < n; i++)
            printf("%5.4f ", y[i]);
    }
    i = wolt(y, n, a);                                     /* wolt��任*/
    if (i) {
        printf("\nwolt of wolt(a):\n");
        for (i = 0; i < n; i++)
            printf("%5.4f ", a[i]);
    }
    i = wolt(b, n, y);                                    /* ��b��wolt�任*/
    if (i) {
        printf("\nwolt of b:\n");
        for (i = 0; i < n; i++)
            printf("%5.4f ", y[i]);
    }
    i = wolt(y, n, b);                                     /*wolt��任*/
    if (i) {
        printf("\nwolt of wolt(b):\n");
        for (i = 0; i < n; i++)
            printf("%5.4f ", b[i]);
    }
    i = hadma(a, n, y);                                     /*��a�Ĺ�����任*/
    if (i) {
        printf("\n\nhadma of a:\n");
        for (i = 0; i < n; i++)
            printf("%5.4f ", y[i]);
    }
    i = hadma(y, n, a);                                    /*��������任*/
    if (i) {
        printf("\nhadma of hadma(a):\n");
        for (i = 0; i < n; i++)
            printf("%5.4f ", a[i]);
    }
    i = hadma(b, n, y);                                    /*��b�Ĺ�����任*/
    if (i) {
        printf("\nhadma of b:\n");
        for (i = 0; i < n; i++)
            printf("%5.4f ", y[i]);
    }
    i = hadma(y, n, b);                                    /*��������任*/
    if (i) {
        printf("\nhadma of hadma(b):\n");
        for (i = 0; i < n; i++)
            printf("%5.4f ", b[i]);
    }
    printf("\n");
}

