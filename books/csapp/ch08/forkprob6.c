/* $begin forkprob6 */
#include "csapp.h"

void doit() {
    if (Fork() == 0) {
        Fork();
        printf("hello %d\n",getpid());
        return;
    }
}

int main() {
    doit();
    printf("hello\n");
    //wait(NULL);
    exit(0);
}
/* $end forkprob6 */
