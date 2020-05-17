#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void *thread_function(void *arg) {
    int i;
    for (i = 0; i < 200; i++) {
        printf("Thread says hi! ---> thread\n");
        sleep(1);
    }
    return NULL;
}

void *thread2_function(void *arg) {
    int i;
    for (i = 0; i < 200; i++) {
        printf("Thread says hi! ---> thread2\n");
        sleep(1);
    }
    return NULL;
}

int main(void) {
    int i = 0;
    pthread_t mythread, mythread2;
    if (pthread_create(&mythread, NULL, thread_function, NULL)) {
        printf("error creating thread.");
        abort();
    }

    if (pthread_create(&mythread2, NULL, thread2_function, NULL)) {
        printf("error creating thread2.");
        abort();
    }
    for (i = 0; i < 200; i++) {
        printf("Main says hi! ---> main\n");
        sleep(1);
    }
    if (pthread_join(mythread, NULL)) {
        printf("error joining thread.");
        abort();
    }
    if (pthread_join(mythread2, NULL)) {
        printf("error joining2 thread.");
        abort();
    }
    exit(0);
}
