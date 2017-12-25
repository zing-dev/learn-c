#include "stdio.h"
#include "stdlib.h"
#include "c_comp.c"                              /* ��Ҫ��������������ļ�*/
#include "c_matmul.c"                            /* ʵϵ��������˺͸�ϵ��������˵ĺ���*/
#include "r_matmul.c"

void main() {
    struct c_comp c_mat1[2][2], c_mat2[2][2], c_mat3[2][2];

    double r_mat1[3][2] = {{1, 2},
                           {3, 4},
                           {1, 4}};   /* ΪҪ��˵�ʵ���󸳳�ֵ*/
    double r_mat2[2][2] = {{5, 6},
                           {7, 8}};
    double r_mat3[3][2];
    int i, j;

    r_matmul(r_mat1, r_mat2, 3, 2, 2, r_mat3);        /* ���ú������м��㲢��ӡ���*/
    printf("real matmul:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++)
            printf("%2.5f ", r_mat3[i][j]);
        printf("\n");
    }
    c_mat1[0][0].rmz = 1;
    c_mat1[0][0].imz = 1;  /* ΪҪ��˵ĸ����󸳳�ֵ*/
    c_mat1[0][1].rmz = 0;
    c_mat1[0][1].imz = 1;
    c_mat1[1][0].rmz = 1;
    c_mat1[1][0].imz = 0;
    c_mat1[1][1].rmz = 2;
    c_mat1[1][1].imz = 3;
    c_mat2[0][0].rmz = 2;
    c_mat2[0][0].imz = 3;
    c_mat2[0][1].rmz = 0;
    c_mat2[0][1].imz = 2;
    c_mat2[1][0].rmz = 2;
    c_mat2[1][0].imz = 1;
    c_mat2[1][1].rmz = 1;
    c_mat2[1][1].imz = 0.5;
    c_matmul(c_mat1, c_mat2, 2, 2, 2, c_mat3);   /* ���ú������м��㲢��ӡ���*/
    printf("complex matmul:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf("%2.5f + (%2.5f)*i ", c_mat3[i][j].rmz, c_mat3[i][j].imz);
        printf("\n");
    }
}
