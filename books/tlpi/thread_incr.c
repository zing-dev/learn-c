//
// Created by zing on 2018/1/25 16:05
// File thread_incr
//

/* thread_incr.c

   This program employs two POSIX threads that increment the same global
   variable, without using any synchronization method. As a consequence,
   updates are sometimes lost.

   See also thread_incr_mutex.c.
*/
#include <pthread.h>
#include <sys/time.h>
#include "tlpi_hdr.h"

static volatile int glob = 0;   /* "volatile" prevents compiler optimizations
                                   of arithmetic operations on 'glob' */
static void *                   /* Loop 'arg' times incrementing 'glob' */
threadFunc(void *arg) {
    int loops = *((int *) arg);
    int loc, j;
    for (j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t t1, t2;
    int loops, s;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    loops = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-loops") : 100000000;

    s = pthread_create(&t1, NULL, threadFunc, &loops);
    if (s != 0)
        errExitEN(s, "pthread_create");
    s = pthread_create(&t2, NULL, threadFunc, &loops);
    if (s != 0)
        errExitEN(s, "pthread_create");

    s = pthread_join(t1, NULL);
    if (s != 0)
        errExitEN(s, "pthread_join");
    s = pthread_join(t2, NULL);
    if (s != 0)
        errExitEN(s, "pthread_join");

    gettimeofday(&end, NULL);
    printf("glob = %d\n", glob);
    printf("运行时间为: %.6f\n", (float)(end.tv_usec - start.tv_usec) * 1.0 / 1000000 + end.tv_sec - start.tv_sec);
    exit(EXIT_SUCCESS);
}