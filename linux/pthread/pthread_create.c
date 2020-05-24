//
// Created by zing on 5/23/2020.
//


#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

static void *thread_start(void *arg) {
    printf("thread_start pid %d thread_id %lx\n",getpid(),pthread_self());
    return NULL;
}

int pthread_create1() {
    pthread_t pthread;
    pthread_attr_t pthreadAttr;
    if (pthread_attr_init(&pthreadAttr) != 0) {
        perror("pthread_attr_init");
        return errno;
    }
    int s = pthread_create(&pthread, &pthreadAttr, &thread_start, NULL);
    if (s != 0) {
        perror("pthread_create");
        return errno;
    }
    s = pthread_create(&pthread, &pthreadAttr, &thread_start, NULL);
    if (s != 0) {
        perror("pthread_create");
        return errno;
    }
    return 0;
}

//void *(*__start_routine) (void *),
void *print1(void *argv) {
    printf("print1 pid %d thread_id %lx\n",getpid(),pthread_self());
    printf("get param { %s }\n",argv);
    for (int i = 0; i < 10; i++) {
        sleep(1);
        printf("print1 %d\n", i);
    }
    return 0;
}

pthread_t pthread_create2() {
    pthread_t pthread;
    if (0 != pthread_create(&pthread, NULL, &print1, "i am from pthread_create2")) {
        perror("pthread_create");
        return errno;
    }
    return pthread;
}

int main(int argc, char *argv[]) {
    printf("main pid %d thread_id %lx\n",getpid(),pthread_self());
    pthread_create1();
    pthread_t p2 = pthread_create2();
    void *rev2;
    pthread_join(p2,&rev2);
    return 0;
}
