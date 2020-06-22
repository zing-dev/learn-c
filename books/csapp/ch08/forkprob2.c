/* $begin forkprob2 */
#include "csapp.h"

void end(void) {
    printf("2\n");
}

int main() {
    if (Fork() == 0)
        atexit(end);
    if (Fork() == 0)
        printf("0\n");
    else
        printf("1\n");
    exit(0);
}
/* $end forkprob2 */

