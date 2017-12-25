#include "stdio.h"
#include "stdlib.h"
#include "c_comp.c"
#include "c_matmul.c"
#include "r_matmul.c"
#include "c_minv.c"
#include "sdminv.c"

void main() {
    struct c_comp c_mat[2][2], c_mat1[2][2], c_mat2[2][2];
    double r_mat[2][2] = {{3, 2},
                          {2, 5}};
    double r_mat1[2][2], r_mat2[2][2];
    int i, j, m, n;

    m = 2;
    n = 2;

    c_mat[0][0].rmz = 2;
    c_mat[0][0].imz = 3;
    c_mat[0][1].rmz = 0;
    c_mat[0][1].imz = 2;
    c_mat[1][0].rmz = 2;
    c_mat[1][0].imz = 1;
    c_mat[1][1].rmz = 1;
    c_mat[1][1].imz = 0.5;

    for (i = 0; i < n; i++)                     /* �������ƻ�ԭ�������ݣ�����ȱ���*/
        for (j = 0; j < n; j++)
            c_mat1[i][j] = c_mat[i][j];
    c_minv(c_mat, n);                        /* ���ú�������*/
    printf("inv(C):\n");                    /* ��ӡ��õ������*/
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%2.5f + (%2.5f)*i ", c_mat[i][j].rmz, c_mat[i][j].imz);
        printf("\n");
    }
    c_matmul(c_mat, c_mat1, n, n, n, c_mat2);    /* ������ԭ�������*/
    printf("C*inv(C):\n");                  /* ��ӡ��˺�Ľ��������֤��ȷ��*/
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%2.5f + (%2.5f)*i ", c_mat2[i][j].rmz, c_mat2[i][j].imz);
        printf("\n");
    }
    for (i = 0; i < n; i++)                     /* �������ƻ�ԭ�������ݣ�����ȱ���*/
        for (j = 0; j < n; j++)
            r_mat1[i][j] = r_mat[i][j];

    printf("\n");
    sdminv(r_mat, n);                         /* ������������*/
    printf("inv(SD):\n");                    /* ��ӡ��õ������*/
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%2.5f ", r_mat[i][j]);
        printf("\n");
    }
    printf("SD*inv(SD):\n");
    r_matmul(r_mat, r_mat1, n, n, n, r_mat2);     /* ���������������*/
    for (i = 0; i < n; i++)                       /* ��ӡ��˵Ľ��*/
    {
        for (j = 0; j < n; j++)
            printf("%2.5f ", r_mat2[i][j]);
        printf("\n");
    }
}

