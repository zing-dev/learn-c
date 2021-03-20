//
// Created by zhangrongxiang on 2018/1/25 15:34
// File simple_thread
//

/* simple_thread.c

   A simple POSIX threads example: create a thread, and then join with it.
*/
#include <pthread.h>
#include "tlpi_hdr.h"

static void *threadFunc(void *arg) {
    char *s = (char *) arg;
    sleep(1);
    printf("%s", s);

    return (void *) strlen(s);
}

int main(int argc, char *argv[]) {
    pthread_t t1, t2;
    void *res;
    int s, s2;

    s = pthread_create(&t1, NULL, threadFunc, "Hello world --------> s \n");
    s2 = pthread_create(&t2, NULL, threadFunc, "Hello world --------> s2 \n");
    if (s != 0)
        errExitEN(s, "pthread_create");

    if (s2 != 0)
        errExitEN(s, "pthread_create");

    printf("Message from main()\n");
    s = pthread_join(t1, &res);
    s2 = pthread_join(t2, &res);
    if (s != 0)
        errExitEN(s, "pthread_join");
    if (s2 != 0)
        errExitEN(s, "pthread_join");

    printf("Thread returned %ld\n", (long) res);

    exit(EXIT_SUCCESS);
}