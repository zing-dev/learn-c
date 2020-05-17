#include "stdio.h"

void main() {
    int k;
    double x, z;
    z = 2.0;
    x = 0.0;
    for (k = 0; k < 10; k++)
        x = x + 0.2;
    printf("z=%2.17f\n", z);
    //z=2.00000000000000000
    printf("z=%2.27f\n", z);
    //z=2.000000000000000000000000000

    printf("x=%2.17f\n", x);
    //x=1.99999999999999978
    printf("x=%2.25f\n", x);
    //x=1.9999999999999997779553951
    printf("x=%2.5f\n", x);
    //x=2.00000
}
