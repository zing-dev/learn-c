//
// Created by zhangrongxiang on 2018/1/26 9:55
// File thread_incr_mutex
//

/* thread_incr_mutex.c

   This program employs two POSIX threads that increment the same global
   variable, synchronizing their access using a mutex. As a consequence,
   updates are not lost. Compare with thread_incr.c, thread_incr_spinlock.c,
   and thread_incr_rwlock.c.
*/
#include <pthread.h>
#include <sys/time.h>
#include "tlpi_hdr.h"

static volatile int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *                   /* Loop 'arg' times incrementing 'glob' */
threadFunc(void *arg) {
    int loops = *((int *) arg);
    int loc, j, s;

    for (j = 0; j < loops; j++) {
        s = pthread_mutex_lock(&mtx);
        if (s != 0)
            errExitEN(s, "pthread_mutex_lock");

        loc = glob;
        loc++;
        glob = loc;

        s = pthread_mutex_unlock(&mtx);
        if (s != 0)
            errExitEN(s, "pthread_mutex_unlock");
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
    printf("运行时间为: %.6f\n", (float) (end.tv_usec - start.tv_usec) * 1.0 / 1000000 + end.tv_sec - start.tv_sec);
    exit(EXIT_SUCCESS);
}