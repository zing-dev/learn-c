//
// Created by zing on 6/21/2020.
//

#include <stdlib.h>
#include <stdio.h>

/* Convert N to base 64 using the digits "./0-9A-Za-z", least-significant
   digit first.  Returns a pointer to static storage overwritten by the
   next call.  */
int main(int argc, char *argv[]) {
    printf("%s\n", l64a(0));
    printf("%s\n", l64a(1));
    printf("%s\n", l64a(2));//0
    printf("%s\n", l64a(10));//8
    printf("%s\n", l64a(16));
    printf("%s\n", l64a(63));//z

    /* Read a number from a string S in base 64 as above.  */
    printf("%ld\n",a64l(l64a(0)));
    printf("%ld\n",a64l(l64a(10)));
    return 0;
}
