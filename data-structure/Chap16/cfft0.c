#include "stdio.h"
#include "math.h"
#include "c_comp.c"
#include "fft.c"
#include "ifft.c"
#include "r2fft.c"

void main() {
    int i;
    struct c_comp x[4], y[4], y1[4], y2[4];
    double a[4], b[4];
    for (i = 0; i < 4; i++)                                 /* ����a��b*/
    {
        a[i] = i + 1;
        b[i] = 2 * i;
    }
    printf(" a sequence\n");
    for (i = 0; i < 4; i++)
        printf("%3.1f ", a[i]);
    printf("\n b sequence\n");
    for (i = 0; i < 4; i++)
        printf("%3.1f ", b[i]);
    for (i = 0; i < 4; i++) {
        x[i].rmz = a[i];
        x[i].imz = 0;
    }
    i = fft(x, 4, y);                                     /*��a��fft*/
    if (i) {
        printf("\n\nfft of a:\n");
        for (i = 0; i < 4; i++)
            printf("%3.1f+i*%3.1f ", y[i].rmz, y[i].imz);
    }
    for (i = 0; i < 4; i++) {
        x[i].rmz = b[i];
        x[i].imz = 0;
    }
    i = fft(x, 4, y);                                    /*��b��fft*/
    if (i) {
        printf("\nfft of b:\n");
        for (i = 0; i < 4; i++)
            printf("%3.1f+i*%3.1f ", y[i].rmz, y[i].imz);
    }
    r2fft(a, b, 4, y1, y2);                               /* ������ʵ����ͬʱ��fft*/
    printf("\n\nr2fft:\n");
    printf("fft of a:\n");
    for (i = 0; i < 4; i++)
        printf("%3.1f+i*%3.1f ", y1[i].rmz, y1[i].imz);
    printf("\nfft of b:\n");
    for (i = 0; i < 4; i++)
        printf("%3.1f+i*%3.1f ", y2[i].rmz, y2[i].imz);
    i = ifft(y1, 4, x);                                /*��fft(a)��ifft*/
    if (i) {
        printf("\n\nifft of fft(b):\n");
        for (i = 0; i < 4; i++)
            printf("%3.1f+i*%3.1f ", x[i].rmz, x[i].imz);
    }
    i = ifft(y2, 4, x);                                /*��fft(b)��ifft*/
    if (i) {
        printf("\nifft of fft(b):\n");
        for (i = 0; i < 4; i++)
            printf("%3.1f+i*%3.1f ", x[i].rmz, x[i].imz);
    }
    printf("\n");
}

