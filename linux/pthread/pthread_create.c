//
// Created by zing on 5/23/2020.
//


#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

static void *thread_start(void *arg) {
    printf("run.....\n");
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t pthread;
    pthread_attr_t pthreadAttr;
    if (pthread_attr_init(&pthreadAttr) != 0){
        perror("pthread_attr_init");
        return errno;
    }
    int s = pthread_create(&pthread, &pthreadAttr, &thread_start, NULL);
    if (s != 0){
        perror("pthread_create");
        return errno;
    }
    s = pthread_create(&pthread, &pthreadAttr, &thread_start, NULL);
    if (s != 0){
        perror("pthread_create");
        return errno;
    }
    sleep(3);
    return 0;
}
