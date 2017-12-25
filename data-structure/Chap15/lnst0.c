#include "stdio.h"
#include "cout.c"
#include "rads.c"

main() {
    int i, j, p[50], p1[50], y[50];
    printf("Data:\n");
    for (i = 0; i < 5; i++)                     /* ����һЩ��������*/
    {
        for (j = 0; j < 10; j++) {
            p[10 * i + j] = 20 + 10 * i - j;
            p1[10 * i + j] = p[10 * i + j];
            printf("%d   ", p[10 * i + j]);
        }
        printf("\n");
    }
    printf("Count Sort:\n");                /* ��������Ľ��*/
    cout(p, y, 50, 60);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++)
            printf("%d   ", y[10 * i + j]);
        printf("\n");
    }
    printf("Radix Sort:\n");                /* ��������Ľ��*/
    rads(p1, 50, 2, 10);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++)
            printf("%d   ", p1[10 * i + j]);
        printf("\n");
    }
}