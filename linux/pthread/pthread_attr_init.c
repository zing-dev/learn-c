//
// Created by zing on 5/24/2020.
//

#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define handle_error_en(en, msg)  do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static void display_pthread_attr(pthread_attr_t *attr, char *prefix);

pthread_attr_t pthreadAttr;

void *start_thread(void *argv) {
    printf("============begin start thread=============\n");
    int s;
    pthread_attr_t gattr;
    s = pthread_getattr_np(pthread_self(), &gattr);
    if (s != 0)
        handle_error_en(s, "pthread_getattr_np");

    printf("Thread attributes:\n");
    display_pthread_attr(&gattr, "\t");
    return 0;
}

static void display_pthread_attr(pthread_attr_t *attr, char *prefix) {
    int s, i;
    size_t v;
    void *stkaddr;
    struct sched_param sp;

    s = pthread_attr_getdetachstate(attr, &i);
    if (s != 0)
        handle_error_en(s, "pthread_attr_getdetachstate");
    printf("%sDetach state        = %s\n", prefix,
           (i == PTHREAD_CREATE_DETACHED) ? "PTHREAD_CREATE_DETACHED" :
           (i == PTHREAD_CREATE_JOINABLE) ? "PTHREAD_CREATE_JOINABLE" :
           "???");

    s = pthread_attr_getscope(attr, &i);
    if (s != 0)
        handle_error_en(s, "pthread_attr_getscope");
    printf("%sScope               = %s\n", prefix,
           (i == PTHREAD_SCOPE_SYSTEM) ? "PTHREAD_SCOPE_SYSTEM" :
           (i == PTHREAD_SCOPE_PROCESS) ? "PTHREAD_SCOPE_PROCESS" :
           "???");

    s = pthread_attr_getinheritsched(attr, &i);
    if (s != 0)
        handle_error_en(s, "pthread_attr_getinheritsched");
    printf("%sInherit scheduler   = %s\n", prefix,
           (i == PTHREAD_INHERIT_SCHED) ? "PTHREAD_INHERIT_SCHED" :
           (i == PTHREAD_EXPLICIT_SCHED) ? "PTHREAD_EXPLICIT_SCHED" :
           "???");

    s = pthread_attr_getschedpolicy(attr, &i);
    if (s != 0)
        handle_error_en(s, "pthread_attr_getschedpolicy");
    printf("%sScheduling policy   = %s\n", prefix,
           (i == SCHED_OTHER) ? "SCHED_OTHER" :
           (i == SCHED_FIFO) ? "SCHED_FIFO" :
           (i == SCHED_RR) ? "SCHED_RR" :
           "???");

    s = pthread_attr_getschedparam(attr, &sp);
    if (s != 0)
        handle_error_en(s, "pthread_attr_getschedparam");
    printf("%sScheduling priority = %d\n", prefix, sp.sched_priority);

    s = pthread_attr_getguardsize(attr, &v);
    if (s != 0)
        handle_error_en(s, "pthread_attr_getguardsize");
    printf("%sGuard size          = %ld bytes\n", prefix, v);

    s = pthread_attr_getstack(attr, &stkaddr, &v);
    if (s != 0)
        handle_error_en(s, "pthread_attr_getstack");
    printf("%sStack address       = %p\n", prefix, stkaddr);
    printf("%sStack size          = 0x%zx bytes\n", prefix, v);
}


int main(int argc, char *argv[]) {

    pthread_t pthread;
    void *ret = NULL;
    pthread_attr_init(&pthreadAttr);

    //PTHREAD_CREATE_DETACHED
    //PTHREAD_CREATE_JOINABLE
    if (pthread_attr_setdetachstate(&pthreadAttr, PTHREAD_CREATE_JOINABLE != 0)) {
        perror("pthread_attr_setdetachstate");
        return errno;
    }

    /* Set the size of the guard area created for stack overflow protection.  */
    if (pthread_attr_setguardsize(&pthreadAttr, 1024) != 0) {
        perror("pthread_attr_setguardsize");
        return errno;
    }

    /* Set scheduling inheritance mode in *ATTR according to INHERIT.  */
    //PTHREAD_INHERIT_SCHED
    //PTHREAD_EXPLICIT_SCHED
    if (pthread_attr_setinheritsched(&pthreadAttr, PTHREAD_EXPLICIT_SCHED)){
        perror("pthread_attr_setinheritsched");
        return errno;
    }

    /* Set scheduling contention scope in *ATTR according to SCOPE.  */
    //PTHREAD_SCOPE_SYSTEM
    //PTHREAD_SCOPE_PROCESS
    int res = pthread_attr_setscope(&pthreadAttr, PTHREAD_SCOPE_PROCESS);
    printf("res %d\n", res);
    if (res != 0) {
        perror("pthread_attr_setscope");
        return errno;
    }

    struct sched_param param = {};
    param.sched_priority = 1;
    pthread_attr_setschedparam(&pthreadAttr, &param);

    pthread_create(&pthread, &pthreadAttr, start_thread, NULL);
    pthread_join(pthread, &ret);
    return 0;
}
