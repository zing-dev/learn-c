#ifndef C_COMP_H
#define C_COMP_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926

struct c_comp {
    double rmz;
    double imz;
} c_comp;

int c_comp_divide(struct c_comp *a1, struct c_comp *a2, struct c_comp *c);

int c_comp_product(struct c_comp *a1, struct c_comp *a2, struct c_comp *c);

#endif