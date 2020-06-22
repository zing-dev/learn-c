/* $begin forkprob4 */
#include "csapp.h"

void doit() {
    Fork();
    Fork();
    printf("doit hello\n");
}

int main() {
    doit();
    printf("hello\n");
    exit(0);
}
/* $end forkprob4 */


