//
// Created by zhangrongxiang on 2018/2/27 13:19
// File drand48
//

#include <stdlib.h>
#include <stdio.h>

/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
int main() {
    double r = drand48();
    printf("%lf\n", r * 10);

    /* Return non-negative, long integer in [0,2^31).  */
    printf("%ld\n",lrand48());

    /* Return signed, long integers in [-2^31,2^31).  */
    printf("%ld\n",mrand48());
    return 0;
}