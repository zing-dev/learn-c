#include "stdio.h"
#include "math.h"

void main() {
    int n;
    double x;
//    如果ax=N（a>0，且a≠1），那么数x叫做以a为底N的对数，记作x=logaN，读作以a为底N的对数，其中a叫做对数的底数，N叫做真数。
    x = log(11.0 / 10.0);
    printf("x 0=%e\n", x);
    for (n = 1; n < 21; n++) {
        x = 1.0 / n - 10 * x;
        printf("x%2d=%e\n", n, x);
    }
}