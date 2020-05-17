//
// Created by zhangrongxiang on 2018/2/1 9:24
// File tsd
//

#include <stdio.h>
#include <pthread.h>
#include <zconf.h>

pthread_key_t key;

void echomsg(int t) {
    printf("destructor excuted in thread %d,param=%d\n", pthread_self(), t);
}

void *child1(void *arg) {
    int tid = pthread_self();
    printf("thread %d enter\n", tid);
    pthread_setspecific(key, (void *) tid);
    sleep(2);
    printf("thread %d returns %d\n", tid, pthread_getspecific(key));
    sleep(5);
}

void *child2(void *arg) {
    int tid = pthread_self();
    printf("thread %d enter\n", tid);
    pthread_setspecific(key, (void *) tid);
    sleep(1);
    printf("thread %d returns %d\n", tid, pthread_getspecific(key));
    sleep(5);
}

int main(void) {
    int tid1, tid2;

    printf("------------------hello-----------------\n");
    pthread_key_create(&key, echomsg);
    pthread_setspecific(key,10);
    pthread_create(&tid1, NULL, child1, NULL);
    pthread_create(&tid2, NULL, child2, NULL);
    sleep(10);
    printf("--> main   %d\n",pthread_getspecific(key));
    pthread_key_delete(key);
    printf("main thread exit\n");
    return 0;
}