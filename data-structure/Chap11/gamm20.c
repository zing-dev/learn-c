#include "stdio.h"
#include "gamm2.c"

main() {
    int i, j;
    double ai, xj, y;
    double e1 = 1.0e-7, e0 = 1.0e-30;               /* ������ֵ���ڲ���ȫ٤�����ļ���*/
    static double a[3] = {0.5, 5.0, 10.0};
    static double x[3] = {0.5, 5.0, 10.0};
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            ai = a[i];                                 /* ѭ��ȡa��x*/
            xj = x[j];
            y = gamm2(ai, xj, e1, e0);                    /* ���ú�����ֵ����ӡ���*/
            printf("gamm2(%2.1f,%2.1f)=%e\n", ai, xj, y);
        }
        printf("\n");
    }
    getchar();
}
