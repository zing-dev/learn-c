//
// Created by zhangrongxiang on 2018/1/25 16:02
// File detached_attrib
//

/* detached_attrib.c

   An example of the use of POSIX thread attributes (pthread_attr_t):
   creating a detached thread.
*/
#include <pthread.h>
#include "tlpi_hdr.h"

static void *threadFunc(void *x) {
    return x;
}

int main(int argc, char *argv[]) {
    pthread_t thr;
    pthread_attr_t attr;
    int s;

    s = pthread_attr_init(&attr);       /* Assigns default values */
    if (s != 0)
        errExitEN(s, "pthread_attr_init");

    s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (s != 0)
        errExitEN(s, "pthread_attr_setdetachstate");

    s = pthread_create(&thr, &attr, threadFunc, (void *) 1);
    if (s != 0)
        errExitEN(s, "pthread_create");

    s = pthread_attr_destroy(&attr);    /* No longer needed */
    if (s != 0)
        errExitEN(s, "pthread_attr_destroy");

    s = pthread_join(thr, NULL);
    if (s != 0)
        errExitEN(s, "pthread_join failed as expected");

    exit(EXIT_SUCCESS);
}