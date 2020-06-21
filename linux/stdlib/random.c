//
// Created by zing on 5/18/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <values.h>

/* These are the functions that actually do things.  The `random', `srandom',
   `initstate' and `setstate' functions are those from BSD Unices.
   The `rand' and `srand' functions are required by the ANSI standard.
   We provide both interfaces to the same random number generator.  */
/* Return a random long integer between 0 and RAND_MAX inclusive.  */

int main(int argc, char *argv[]) {
    printf("%d\n",RAND_MAX);
    printf("%d\n",INT_MAX);

    time_t time1;
    time(&time1);
    /* Seed the random number generator with the given number.  */
    srandom(time1);
    for (int i = 0; i < 2; i++) {
        printf("%ld\n", random());
    }
    return 0;
}
