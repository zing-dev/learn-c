#include "stdio.h"
#include "r_mqr.c"
#include "r_matmul.c"

main() {
    int i, j;
    double q[4][4], mat[4][3] = {{1.0,  2.0,  4.0},          /* ����A��ֵ*/
                                 {-1.0, 0.0,  3.0},
                                 {2.0,  -1.0, 0.0},
                                 {3.0,  1.0,  2.0}};
    double mat3[4][3];
    i = r_mqr(mat, 4, 3, q, 1e-16);                         /* ����QR�ֽ�*/
    if (i != 0) {
        printf("Q:\n");                                 /* ��ӡQ����*/
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++)
                printf("%2.5f ", q[i][j]);
            printf("\n");
        }
        printf("\n");
        printf("R:\n");                                 /* ��ӡ�ֽ�õ���R*/
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++)
                printf("%2.5f ", mat[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    r_matmul(q, mat, 4, 4, 3, mat3);                     /* Q*R����֤���*/
    printf("Q*R:\n");                                 /* ��ӡQ*R�Ľ��*/
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++)
            printf("%2.5f ", mat3[i][j]);
        printf("\n");
    }
}

