#include "stdio.h"
#include "math.h"

void main() {
    double x1, x2;
    x1 = (pow(10, 18) + 1 + sqrt((pow(10, 18) + 1) * (pow(10, 18) + 1) - 4 * 1 * pow(10, 18))) / 2;
    x2 = (pow(10, 18) + 1 - sqrt((pow(10, 18) + 1) * (pow(10, 18) + 1) - 4 * 1 * pow(10, 18))) / 2;
    printf("x1=%e\n", x1);
    //x1=1.000000e+18
    printf("x2=%e\n", x2);
    //x2=0.000000e+00

//    a = 1;
//    b = pow(10, 18) + 1;
//    c = pow(10, 18);
//    x = (-b +- sqrt(b * b -4ac)) / (2 * a)
    printf("%.10f",pow(10, 18));

} 