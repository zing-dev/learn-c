#include "c_comp.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "c_comp_exp.c"
#include "c_comp_log.c"
#include "c_comp_sin.c"
#include "c_comp_cos.c"
#include "c_comp_power.c"
#include "c_comp_nthroot.c"

void main() {
    struct c_comp a, b, c, f, g, h;
    struct c_comp d[5];
    int n = 5, i;

    a.rmz = 5.5;
    a.imz = 3.7;


    if (c_comp_power(&a, &c, n)) {
        printf("5�γ��ݵĽ��Ϊ��\n");
        printf("%1.5f+j%1.5f\n", c.rmz, c.imz);
    }
    if (c_comp_nthroot(&a, &d, n)) {
        printf("5�η����Ľ��Ϊ��\n");
        for (i = 0; i < 5; i++)
            printf("%1.5f+j%1.5f\n", d[i].rmz, d[i].imz);
    }
    if (c_comp_exp(&a, &b)) {
        printf("ָ���Ľ��Ϊ��\n");
        printf("%1.5f+j%1.5f\n", b.rmz, b.imz);
    }
    if (c_comp_log(&a, &f)) {
        printf("�����Ľ��Ϊ��\n");
        printf("%1.5f+j%1.5f\n", f.rmz, f.imz);
    }
    if (c_comp_sin(&a, &g)) {
        printf("���ҵĽ��Ϊ��\n");
        printf("%1.5f+j%1.5f\n", g.rmz, g.imz);
    }
    if (c_comp_cos(&a, &h)) {
        printf("���ҵĽ��Ϊ��\n");
        printf("%1.5f+j%1.5f\n", h.rmz, h.imz);
    }
}
