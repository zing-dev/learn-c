#include "stdio.h"
#include "stdlib.h"
#include "randu01s.c"
#include "c2test.c"

void main() {
    int L, i, *a, *e, r, k, v, temp;
    double *u_ran, c2, alpha;

    L = 10000;
    alpha = 0.05;
    r = 10;
    k = 1;
    a = (int *) malloc(sizeof(int) * r);
    e = (int *) malloc(sizeof(int) * r);
    u_ran = (double *) malloc(sizeof(double) * L);
    randu01s(L, u_ran);//����L��[0,1]����ľ��������

    for (i = 0; i < r; i++) {
        e[i] = L / r;  //ÿ��������L/r
        a[i] = 0;
    }

    for (i = 0; i < L; i++)
        a[(int) (u_ran[i] * 10)]++;

    temp = c2test(a, e, r, k, &v, &c2, alpha);

    printf("v=%d  c2=%1.5f\n", v, c2);
    if (temp)
        printf("���Ϸֲ�\n");
    else
        printf("�����Ϸֲ�\n");
}
	

