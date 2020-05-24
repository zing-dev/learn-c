//
// Created by zing on 5/24/2020.
//

#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <errno.h>

void *child_thread(void *arg) {
    int policy;
    int max_priority = 0, min_priority = 0;
    struct sched_param param;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    if (pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED) != 0) {
        printf("setinheritsched %d\n", errno);
    }
    pthread_attr_getinheritsched(&attr, &policy);
    printf("getinheritsched %s\n",
           policy == PTHREAD_EXPLICIT_SCHED ? "PTHREAD_EXPLICIT_SCHED" : policy == PTHREAD_INHERIT_SCHED
                                                                         ? "PTHREAD_INHERIT_SCHED" : "error");
    int res = pthread_attr_setschedpolicy(&attr, SCHED_RR);
    if (res != 0) {
        printf("policy:errno %d,real value%d\n", errno, res);
    }
    printf("res %d\n", res);
    if (res != 0) {
        printf("policy:errno %d,%d\n", errno, res);
    }
    printf("schedpolicy %s\n",
           policy == SCHED_FIFO ? "SCHED_FIFO" : policy == SCHED_FIFO ? "SCHED_FIFO" : policy == SCHED_OTHER
                                                                                       ? "SCHED_OTHER" : "err");
    sched_get_priority_max(max_priority);
    sched_get_priority_max(min_priority);
    printf("max_priority:%d\n", max_priority);
    printf("min_priority:%d\n", min_priority);

    param.sched_priority = max_priority;
    pthread_attr_setschedparam(&attr, &param);
    printf("sched_priority:%d\n", param.sched_priority);
    pthread_attr_destroy(&attr);
    return 0;
}


int main(int argc, char *argv[]) {
    pthread_t pthread;
    pthread_create(&pthread, NULL, child_thread, NULL);
    pthread_join(pthread, NULL);
    return 0;
}
