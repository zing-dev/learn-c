#include "stdio.h"
#include "smldl.c"

main() {
    int i, j;
    double L[5][5], D[5];
    double a[5][5] = {{12.0, 7.0,  5.0,  2.0,  -1.0},          /* ����A*/
                      {7.0,  9.0,  6.0,  3.0,  -2.0},
                      {5.0,  6.0,  5.0,  -7.0, 1.0},
                      {2.0,  3.0,  -7.0, -1.0, 8.0},
                      {-1.0, -2.0, 1.0,  8.0,  3.0}};

    smldl(a, 5, L, D, 1e-16);                                   /* A���Ʊ任Ϊ���Խ���*/
    printf("MAT L IS:\n");                                /* ��ӡQ����*/
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            printf("%2.5f ", L[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("MAT D IS:\n");                              /* ��ӡ���Խ���*/
    for (i = 0; i < 5; i++)
        printf("%2.5f ", D[i]);
    printf("\n");

    getchar();
}
