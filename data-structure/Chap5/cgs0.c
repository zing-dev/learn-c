#include "stdio.h"
#include "c_comp.c"
#include "c_gaus.c"
#include "c_gsjd.c"

main() {
    int i, j;
    struct c_comp a[3][3], a1[3][3], b[3], b1[3], x[3], x1[3];  /* �����ṹ������*/
    a[0][0].rmz = 1.0;
    a[0][0].imz = 0.5;
    a[0][1].rmz = .5;
    a[0][1].imz = 1.5;
    a[0][2].rmz = 2.0;
    a[0][2].imz = 3.5;
    a[1][0].rmz = 1.5;
    a[1][0].imz = 2.0;
    a[1][1].rmz = 1.0;
    a[1][1].imz = -0.5;
    a[1][2].rmz = -0.5;
    a[1][2].imz = 1.5;
    a[2][0].rmz = -1.0;
    a[2][0].imz = 0.5;
    a[2][1].rmz = -1.5;
    a[2][1].imz = -1.5;
    a[2][2].rmz = 1.0;
    a[2][2].imz = 2.5;                    /* ϵ�����󸳳�ֵ*/
    b[0].rmz = .5;
    b[0].imz = 1.5;
    b[1].rmz = -1.0;
    b[1].imz = -0.5;
    b[2].rmz = 1.5;
    b[2].imz = 2.5;                          /* ������������ֵ*/
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)                                  /* ���ú������ƻ�����*/
        {                                                   /* ���Ҫ����һ��*/
            a1[i][j].rmz = a[i][j].rmz;
            a1[i][j].imz = a[i][j].imz;
        }
        b1[i].rmz = b[i].rmz;
        b1[i].imz = b[i].imz;
    }
    printf("GAUSS:\n");                                   /* ��˹��Ԫ��*/
    if (c_gaus(a1, b1, x1, 3, 1e-16) != 0)
        for (i = 0; i < 3; i++)                                    /* ��ӡ���*/
            printf("x1(%d)=%2.5f +(%2.5fi)\n", i, x1[i].rmz, x1[i].imz);
    printf("\nGAUSS JORDAN:\n");
    if (c_gsjd(a, b, x, 3, 1e-16) != 0)                          /* ��˹��Լ����ȥ��*/
        for (i = 0; i < 3; i++)
            printf("x2(%d)=%2.5f +(%2.5fi)\n", i, x[i].rmz, x[i].imz); /* ��ӡ���*/
}
