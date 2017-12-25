#include "stdio.h"
#include "smtr.c"

main() {
    int i, j;
    static double q[5][5];
    static double a[5][5] = {{12.0, 7.0,  5.0,  2.0,  -1.0},          /* ����A*/
                             {7.0,  9.0,  6.0,  3.0,  -2.0},
                             {5.0,  6.0,  5.0,  -7.0, 1.0},
                             {2.0,  3.0,  -7.0, -1.0, 8.0},
                             {-1.0, -2.0, 1.0,  8.0,  2.0}};
    smtr(a, 5, q, 1e-16);                                   /* A���Ʊ任Ϊ���Խ���*/
    printf("MAT Q IS:\n");                                /* ��ӡQ����*/
    for (i = 0; i <= 4; i++) {
        for (j = 0; j <= 4; j++)
            printf("%2.5f ", q[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("MAT TR IS:\n");                              /* ��ӡ���Խ���*/
    for (i = 0; i <= 4; i++) {
        for (j = 0; j <= 4; j++)
            printf("%2.5f ", a[i][j]);
        printf("\n");
    }
}
