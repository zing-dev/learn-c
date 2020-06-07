//
// Created by zing on 6/7/2020.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("  F    C  \n");
    printf("----------\n");

    fahr = (float) lower;
    while (fahr <= (float) upper) {
        celsius = (float) ((5.0 / 9.0) * (fahr - 32.0));
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + (float) step;
    }
    return EXIT_SUCCESS;
}
