/* $begin restart */
#include "csapp.h"

sigjmp_buf buf;

/* Jump to the environment saved in ENV, making the
   sigsetjmp call there return VAL, or 1 if VAL is 0.
   Restore the signal mask if that sigsetjmp call saved it.
   This is just an alias `longjmp'.  */
void handler(int sig) {
    siglongjmp(buf, 1);
}

int main() {
    int i = 0;
    Signal(SIGINT, handler);

    if (!sigsetjmp(buf, 1))
        printf("starting\n");
    else
        printf("restarting\n");

    while (i++ < 100) {
        Sleep(1);
        sleep(1);
        printf("processing...\n");
    }
    exit(0);
}
/* $end restart */
