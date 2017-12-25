#include "stdio.h"
#include "mima.c"
#include "mmas.c"
#include "bist.c"
#include "qcks.c"

main() {
    int i, j, p[50], ma, mi, m12;
    printf("Data:\n");
    for (i = 0; i < 5; i++)                            /* ����һЩ��������*/
    {
        for (j = 0; j < 10; j++) {
            p[10 * i + j] = 20 + 10 * i - j;
            printf("%d   ", p[10 * i + j]);
        }
        printf("\n");
    }
    printf("mima:\n");                           /* �����ֵ����Сֵ*/
    mima(p, 50, &mi, &ma);
    printf("min = %d , max = %d\n", mi, ma);
    printf("mmas:\n");
    mmas(p, 50, 12);                               /* �ҵ�12���Ԫ��*/
    m12 = p[11];
    printf("The 12th smallest m12 is: %d\n", m12);
    qcks(p, 0, 49);                                 /* ����*/
    i = bist(p, 50, m12);                           /* ���ֲ���*/
    printf("m12's position in the ordered sqeu is: %d\n", i);
}
